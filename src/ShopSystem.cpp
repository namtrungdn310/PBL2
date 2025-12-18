#include "../include/ShopSystem.h"
#include "../include/FileManager.h"
#include <QString>
#include <ctime>

ShopSystem* ShopSystem::instance = nullptr;

ShopSystem::ShopSystem() : currentCustomer(nullptr), currentStaff(nullptr), monthlyRevenueTarget(50000000.0), lastUserId(0), lastProductId(0), lastCategoryId(0), lastOrderId(0), lastInvoiceId(0), lastPromoId(0), lastReviewId(0) {}
ShopSystem::~ShopSystem() {}

ShopSystem* ShopSystem::getInstance() {
    if (instance == nullptr) instance = new ShopSystem();
    return instance;
}

void ShopSystem::addProduct(const Product& product) { products.push_back(product); }

void ShopSystem::removeProduct(int productId) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getProductId() == productId) {
            products.erase(products.begin() + i);
            break;
        }
    }
}

Product* ShopSystem::findProduct(int productId) { //tìm kiếm nhị phân
    auto getId = [](const Product& p) { return p.getProductId(); };

    int index = Algorithms::binarySearch(products, productId, (int(*)(const Product&))getId);

    if (index != -1) {
        return &products[index];
    }
    return nullptr;
}

void ShopSystem::addCustomer(const Customer& c) { customers.push_back(c); }

Customer* ShopSystem::findCustomer(int userId) {
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getUserId() == userId) return &customers[i];
    }
    return nullptr;
}

Customer* ShopSystem::findCustomerByEmail(const string& email) {
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getEmail() == email) return &customers[i];
    }
    return nullptr;
}

Staff* ShopSystem::findStaff(int userId) {
    for (size_t i = 0; i < staffMembers.size(); i++) {
        if (staffMembers[i].getUserId() == userId) return &staffMembers[i];
    }
    return nullptr;
}

Order* ShopSystem::findOrder(int orderId) {
    for (size_t i = 0; i < orders.size(); i++) {
        if (orders[i].getOrderId() == orderId) return &orders[i];
    }
    return nullptr;
}

void ShopSystem::removePromotion(int promoId) {
    for (size_t i = 0; i < promotions.size(); i++) {
        if (promotions[i].getPromoId() == promoId) {
            promotions.erase(promotions.begin() + i);
            break;
        }
    }
}

string ShopSystem::getCategoryName(int catId) const {
    for (size_t i = 0; i < categories.size(); i++) {
        if (categories[i].getCategoryId() == catId) return categories[i].getName();
    }
    return "Unknown";
}

MyVector<Review> ShopSystem::getReviewsForProduct(int productId) const {
    MyVector<Review> res;
    for (size_t i = 0; i < reviews.size(); i++) {
        if (reviews[i].getProductId() == productId) res.push_back(reviews[i]);
    }
    return res;
}

bool ShopSystem::loginCustomer(const string& email, const string& password) {
    Customer* c = findCustomerByEmail(email);
    if (c && c->login(email, password)) {
        currentCustomer = c;
        currentStaff = nullptr;
        currentCart = Cart(c->getUserId());

        if (savedUserCarts.count(c->getUserId())) {
            MyVector<CartItem> items = savedUserCarts[c->getUserId()];
            for (size_t i = 0; i < items.size(); i++) {
                currentCart.addItem(items[i].getProduct().getProductId(), items[i].getSelectedSize(), items[i].getQuantity(), items[i].getProduct());
            }
        }
        return true;
    }
    return false;
}

bool ShopSystem::loginStaff(const string& email, const string& password) {
    for (size_t i = 0; i < staffMembers.size(); i++) {
        if (staffMembers[i].login(email, password)) {
            currentStaff = &staffMembers[i];
            currentCustomer = nullptr;
            return true;
        }
    }
    return false;
}

void ShopSystem::logout() {
    if (currentCustomer) {
        savedUserCarts[currentCustomer->getUserId()] = currentCart.getItems();
        FileManager::writeCarts("data/carts.txt", savedUserCarts);
    }
    currentCustomer = nullptr;
    currentStaff = nullptr;
    currentCart.clearCart();
}

int ShopSystem::registerNewCustomer(const string& name, const string& email, const string& pass, const string& address, const string& phone) {
    if (findCustomerByEmail(email)) return 1;
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getPhone() == phone) return 2;
    }
    int newId = getNewUserId();

    Customer newCust(newId, name, email, pass, address, phone, 50);
    addCustomer(newCust);
    saveAllData();
    return 0;
}

void ShopSystem::loadAllData() { // sắp xếp sản phẩm tăng dần ID: quick sort
    FileManager::createDataFolder();
    FileManager::initializeDataFiles();
    categories = FileManager::readCategories("data/categories.txt");
    customers = FileManager::readCustomers("data/customers.txt");
    staffMembers = FileManager::readStaff("data/staff.txt");
    orders = FileManager::readOrders("data/orders.txt");
    promotions = FileManager::readPromotions("data/promotions.txt");
    reviews = FileManager::readReviews("data/reviews.txt");
    invoices = FileManager::readInvoices("data/invoices.txt");
    products = FileManager::readProducts("data/products.txt");

    Algorithms::sort(products, [](const Product& a, const Product& b) {
        return a.getProductId() < b.getProductId();
    });

    lastUserId = 0;
    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getUserId() > lastUserId) lastUserId = customers[i].getUserId();
    }
    for (size_t i = 0; i < staffMembers.size(); i++) {
        if (staffMembers[i].getUserId() > lastUserId) lastUserId = staffMembers[i].getUserId();
    }

    lastProductId = 0;
    for (size_t i = 0; i < products.size(); i++) if (products[i].getProductId() > lastProductId) lastProductId = products[i].getProductId();

    lastCategoryId = 0;
    for (size_t i = 0; i < categories.size(); i++) if (categories[i].getCategoryId() > lastCategoryId) lastCategoryId = categories[i].getCategoryId();

    lastOrderId = 0;
    for (size_t i = 0; i < orders.size(); i++) {
        if (orders[i].getOrderId() > lastOrderId) lastOrderId = orders[i].getOrderId();
    }

    lastInvoiceId = 0;
    for (size_t i = 0; i < invoices.size(); i++) {
        if (invoices[i].getInvoiceId() > lastInvoiceId) lastInvoiceId = invoices[i].getInvoiceId();
    }

    lastPromoId = 0;
    for (size_t i = 0; i < promotions.size(); i++) {
        if (promotions[i].getPromoId() > lastPromoId) lastPromoId = promotions[i].getPromoId();
    }

    lastReviewId = 0;
    for (size_t i = 0; i < reviews.size(); i++) {
        if (reviews[i].getReviewId() > lastReviewId) lastReviewId = reviews[i].getReviewId();
    }

    MyMap<int, MyVector<OrderItem>> itemsMap = FileManager::readOrderItems("data/order_items.txt", products);
    for (size_t i = 0; i < orders.size(); i++) {
        int oid = orders[i].getOrderId();
        if (itemsMap.count(oid)) {
            MyVector<OrderItem> items = itemsMap[oid];
            for (size_t j = 0; j < items.size(); j++) {
                orders[i].addOrderItem(items[j]);
            }
        }
    }

    MyMap<int, MyVector<Pair<string, int>>> stockMap = FileManager::readInventoryStock("data/inventory_stock.txt");
    for (size_t i = 0; i < products.size(); i++) {
        int prodId = products[i].getProductId();
        if (stockMap.count(prodId)) {
            int sizeId = 1;
            MyVector<Pair<string, int>> stockList = stockMap[prodId];
            for (size_t j = 0; j < stockList.size(); j++) {
                // stockList[j] là Pair<string, int>
                Size size(sizeId++, stockList[j].first, stockList[j].second);
                products[i].addSize(size);
            }
        }
    }

    savedUserCarts = FileManager::readCarts("data/carts.txt", products);
}

void ShopSystem::saveAllData() {
    if (currentCustomer) {
        savedUserCarts[currentCustomer->getUserId()] = currentCart.getItems();
    }
    FileManager::writeCustomers("data/customers.txt", customers);
    FileManager::writeStaff("data/staff.txt", staffMembers);
    FileManager::writeProducts("data/products.txt", products);
    FileManager::writeOrders("data/orders.txt", orders);
    FileManager::writePromotions("data/promotions.txt", promotions);
    FileManager::writeReviews("data/reviews.txt", reviews);
    FileManager::writeInvoices("data/invoices.txt", invoices);
    FileManager::writeInventoryStock("data/inventory_stock.txt", products);
    FileManager::writeCarts("data/carts.txt", savedUserCarts);
    FileManager::writeOrderItems("data/order_items.txt", orders);
    FileManager::writeCategories("data/categories.txt", categories);
}

double ShopSystem::getTotalRevenue() const {
    double total = 0;
    for (size_t i = 0; i < orders.size(); i++) {
        if (orders[i].getStatus() == "Completed") total += orders[i].getTotalAmount();
    }
    return total;
}

double ShopSystem::getRevenueThisMonth() const {
    double monthlyTotal = 0;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentMonth = 1 + ltm->tm_mon;
    int currentYear = 1900 + ltm->tm_year;

    for (size_t i = 0; i < orders.size(); i++) {
        if (orders[i].getStatus() == "Completed") {
            time_t orderDate = orders[i].getOrderDate();
            tm* ltmOrder = localtime(&orderDate);
            if ((1 + ltmOrder->tm_mon) == currentMonth && (1900 + ltmOrder->tm_year) == currentYear) {
                monthlyTotal += orders[i].getTotalAmount();
            }
        }
    }
    return monthlyTotal;
}

int ShopSystem::getAvailableStock(int productId, const string& sizeName) {
    Product* p = findProduct(productId);
    if (!p) return 0;

    Size* s = p->findSize(sizeName);
    if (!s) return 0;

    int realStock = s->getQuantity();
    int inCart = currentCart.getQuantityInCart(productId, sizeName);
    return (realStock - inCart > 0) ? (realStock - inCart) : 0;
}


MyVector<Product> ShopSystem::searchProducts(int categoryId, string keyword, long long minPrice, long long maxPrice, SortOption sortOption) {
    MyVector<Product> result;
    QString qKeyword = QString::fromStdString(keyword);
    for (size_t i = 0; i < products.size(); i++) { // tìm kiếm tuyến tính sản phẩm
        const Product& p = products[i];
        bool catOk = (categoryId == 0) || (p.getCategoryId() == categoryId);

        bool keyOk = true;
        if (!keyword.empty()) {
            QString qName = QString::fromStdString(p.getName());
            if (!qName.contains(qKeyword, Qt::CaseInsensitive)) {
                keyOk = false;
            }
        }

        bool priceOk = true;
        if (p.getPrice() < minPrice) priceOk = false;
        if (maxPrice != -1 && p.getPrice() > maxPrice) priceOk = false;

        if (catOk && keyOk && priceOk) {
            result.push_back(p);
        }
    }

    if (sortOption == PRICE_ASC) { // quick sort
        Algorithms::sort(result, [](const Product& a, const Product& b) {
            return a.getPrice() < b.getPrice();
        });
    } else if (sortOption == PRICE_DESC) {
        Algorithms::sort(result, [](const Product& a, const Product& b) {
            return a.getPrice() > b.getPrice();
        });
    }

    return result;
}

string ShopSystem::validateCartStock() {
    string message = "";
    MyVector<int> itemsToRemove;
    MyVector<CartItem>& cartItems = currentCart.getItems();

    for (size_t i = 0; i < cartItems.size(); ++i) {
        CartItem& item = cartItems[i];
        int prodId = item.getProduct().getProductId();
        string sizeName = item.getSelectedSize();
        int currentQty = item.getQuantity();

        Product* realProd = findProduct(prodId);
        if (!realProd) {
            message += "- '" + item.getProduct().getName() + "' is no longer available -> Removed from cart.\n";
            itemsToRemove.push_back((int)i);
            continue;
        }

        Size* realSize = realProd->findSize(sizeName);
        int realStock = (realSize) ? realSize->getQuantity() : 0;

        if (realStock == 0) {
            message += "- '" + realProd->getName() + " (" + sizeName + ")' is out of stock -> Removed from cart.\n";
            itemsToRemove.push_back((int)i);
        }
        else if (currentQty > realStock) {
            item.updateQuantity(realStock);
            message += "- '" + realProd->getName() + " (" + sizeName + ")' only has " + to_string(realStock) + " left -> Quantity updated.\n";
        }
    }

    for (int i = itemsToRemove.size() - 1; i >= 0; --i) {
        currentCart.removeItem(itemsToRemove[i]);
    }

    return message;
}

void ShopSystem::deleteCurrentCustomer() {
    if (!currentCustomer) return;
    int deletedId = currentCustomer->getUserId();
    string deletedName = currentCustomer->getName();

    for (int i = orders.size() - 1; i >= 0; i--) {
        if (orders[i].getCustomerId() == deletedId) {
            orders.erase(orders.begin() + i);
        }
    }

    string replyPrefix = "Replying to " + deletedName + ":";
    for (int i = reviews.size() - 1; i >= 0; i--) {
        bool isReviewByThisCustomer = (reviews[i].getCustomerId() == deletedId);
        bool isStaffReplyToThisCustomer = (reviews[i].getRating() == 0 && reviews[i].getComment().find(replyPrefix) == 0);

        if (isReviewByThisCustomer || isStaffReplyToThisCustomer) {
            reviews.erase(reviews.begin() + i);
        }
    }

    savedUserCarts.erase(deletedId);

    logout();

    for (size_t i = 0; i < customers.size(); i++) {
        if (customers[i].getUserId() == deletedId) {
            customers.erase(customers.begin() + i);
            break;
        }
    }
    saveAllData();
}

int ShopSystem::getNewUserId() { return ++lastUserId; }
int ShopSystem::getNewProductId() { return ++lastProductId; }
int ShopSystem::getNewCategoryId() { return ++lastCategoryId; }
int ShopSystem::getNewOrderId() { return ++lastOrderId; }
int ShopSystem::getNewInvoiceId() { return ++lastInvoiceId; }
int ShopSystem::getNewPromoId() { return ++lastPromoId; }

void ShopSystem::staffConfirmCancelOrder(int orderId) {
    Order* order = findOrder(orderId);
    if (!order) return;

    string oldStatus = order->getStatus();
    if (oldStatus == "Cancelled") return;

    const MyVector<OrderItem>& items = order->getItems();
    for (size_t i = 0; i < items.size(); i++) {
        Product* p = findProduct(items[i].getProduct().getProductId());
        if (p) p->updateStock(items[i].getSelectedSize(), items[i].getQuantity());
    }

    Customer* cust = findCustomer(order->getCustomerId());
    if (cust) {
        int currentPoints = cust->getLoyaltyPoints();
        int pointsUsed = static_cast<int>(order->getPointsDiscount() / 100.0);
        int pointsEarned = 0;
        if (oldStatus == "Completed") {
            pointsEarned = static_cast<int>(order->getTotalAmount() / 1000.0);
        }
        int newPoints = currentPoints + pointsUsed - pointsEarned;
        if (newPoints < 0) newPoints = 0;
        cust->setLoyaltyPoints(newPoints);
    }

    order->setStatus("Cancelled");
    saveAllData();
}

void ShopSystem::staffConfirmCompleteOrder(int orderId) {
    Order* order = findOrder(orderId);
    if (!order) return;

    if (order->getStatus() != "Pending") return;

    order->setStatus("Completed");

    Customer* cust = findCustomer(order->getCustomerId());
    if (cust) {
        int earnedPoints = static_cast<int>(order->getTotalAmount() / 1000.0);
        cust->addLoyaltyPoints(earnedPoints);
    }
    saveAllData();
}

int ShopSystem::countTotalInCarts(int productId, const string& sizeName) {
    int total = 0;

    for (const auto& entry : savedUserCarts) {
        const MyVector<CartItem>& items = entry.second;
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].getProduct().getProductId() == productId &&
                items[i].getSelectedSize() == sizeName) {
                total += items[i].getQuantity();
            }
        }
    }

    MyVector<CartItem>& currentItems = currentCart.getItems();
    for (size_t i = 0; i < currentItems.size(); i++) {
        const CartItem& item = currentItems[i];
        if (item.getProduct().getProductId() == productId && item.getSelectedSize() == sizeName) {
            total += item.getQuantity();
        }
    }
    return total;
}

MyVector<Promotion>& ShopSystem::getPromotions() {
    return this->promotions;
}

void ShopSystem::removeReview(int reviewId) {
    for (size_t i = 0; i < reviews.size(); i++) {
        if (reviews[i].getReviewId() == reviewId) {
            reviews.erase(reviews.begin() + i);
            break;
        }
    }
    saveAllData();
}

int ShopSystem::getNewReviewId() { return ++lastReviewId; }

void ShopSystem::addStaff(const Staff& s) {
    staffMembers.push_back(s);
    saveAllData();
}

void ShopSystem::removeStaff(int staffId) {
    for (size_t i = 0; i < staffMembers.size(); i++) {
        if (staffMembers[i].getUserId() == staffId) {
            staffMembers.erase(staffMembers.begin() + i);
            break;
        }
    }
    saveAllData();
}

void ShopSystem::updateStaff(const Staff& s) {
    for (size_t i = 0; i < staffMembers.size(); i++) {
        if (staffMembers[i].getUserId() == s.getUserId()) {
            staffMembers[i] = s; // Gán chồng lên
            break;
        }
    }
    saveAllData();
}
