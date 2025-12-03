#include "../include/ShopSystem.h"
#include "../include/FileManager.h"
#include <QString>
#include <algorithm>
#include <ctime> 

ShopSystem* ShopSystem::instance = nullptr;

ShopSystem::ShopSystem() : currentCustomer(nullptr), currentStaff(nullptr), monthlyRevenueTarget(50000000.0), lastUserId(0), lastProductId(0), lastCategoryId(0), lastOrderId(0), lastInvoiceId(0), lastPromoId(0) {}
ShopSystem::~ShopSystem() {}

ShopSystem* ShopSystem::getInstance() {
    if (instance == nullptr) instance = new ShopSystem();
    return instance;
}

void ShopSystem::addProduct(const Product& product) { products.push_back(product); }
void ShopSystem::removeProduct(int productId) {
    products.erase(remove_if(products.begin(), products.end(), [productId](const Product& p) { return p.getProductId() == productId; }), products.end());
}
Product* ShopSystem::findProduct(int productId) {
    for (auto& p : products) if (p.getProductId() == productId) return &p;
    return nullptr;
}

void ShopSystem::addCustomer(const Customer& c) { customers.push_back(c); }
Customer* ShopSystem::findCustomer(int userId) {
    for (auto& c : customers) if (c.getUserId() == userId) return &c;
    return nullptr;
}
Customer* ShopSystem::findCustomerByEmail(const string& email) {
    for (auto& c : customers) if (c.getEmail() == email) return &c;
    return nullptr;
}

void ShopSystem::addStaff(const Staff& s) { staffMembers.push_back(s); }
Staff* ShopSystem::findStaff(int userId) {
    for (auto& s : staffMembers) if (s.getUserId() == userId) return &s;
    return nullptr;
}

void ShopSystem::addOrder(const Order& o) { orders.push_back(o); }
Order* ShopSystem::findOrder(int orderId) {
    for (auto& o : orders) if (o.getOrderId() == orderId) return &o;
    return nullptr;
}

void ShopSystem::addPromotion(const Promotion& p) { promotions.push_back(p); }
void ShopSystem::removePromotion(int promoId) {
    promotions.erase(remove_if(promotions.begin(), promotions.end(), [promoId](const Promotion& p) { return p.getPromoId() == promoId; }), promotions.end());
}

void ShopSystem::addCategory(const Category& c) { categories.push_back(c); }
string ShopSystem::getCategoryName(int catId) const {
    for (const auto& cat : categories) if (cat.getCategoryId() == catId) return cat.getName();
    return "Unknown";
}

void ShopSystem::addInvoice(const Invoice& i) { invoices.push_back(i); }
void ShopSystem::addReview(const Review& r) { reviews.push_back(r); }
vector<Review> ShopSystem::getReviewsForProduct(int productId) const {
    vector<Review> res;
    for (const auto& r : reviews) if (r.getProductId() == productId) res.push_back(r);
    return res;
}

bool ShopSystem::loginCustomer(const string& email, const string& password) {
    Customer* c = findCustomerByEmail(email);
    if (c && c->login(email, password)) {
        currentCustomer = c;
        currentStaff = nullptr;
        currentCart = Cart(c->getUserId());

        if (savedUserCarts.count(c->getUserId())) {
            for (const auto& item : savedUserCarts[c->getUserId()]) {
                currentCart.addItem(item.getProduct().getProductId(), item.getSelectedSize(), item.getQuantity(), item.getProduct());
            }
        }

        return true;
    }
    return false;
}

bool ShopSystem::loginStaff(const string& email, const string& password) {
    for (auto& s : staffMembers) {
        if (s.login(email, password)) {
            currentStaff = &s;
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
    for (const auto& c : customers) if (c.getPhone() == phone) return 2;
    int newId = getNewUserId();

    Customer newCust(newId, name, email, pass, address, phone, 50);
    addCustomer(newCust);
    saveAllData();
    return 0;
}

void ShopSystem::loadAllData() {
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
    
    lastUserId = 0;
    for (const auto& c : customers) {
        if (c.getUserId() > lastUserId) lastUserId = c.getUserId();
    }
    for (const auto& s : staffMembers) {
        if (s.getUserId() > lastUserId) lastUserId = s.getUserId();
    }

    lastProductId = 0;
    for (const auto& p : products) if (p.getProductId() > lastProductId) lastProductId = p.getProductId();

    lastCategoryId = 0;
    for (const auto& c : categories) if (c.getCategoryId() > lastCategoryId) lastCategoryId = c.getCategoryId();

    lastOrderId = 0;
    for (const auto& o : orders) {
        if (o.getOrderId() > lastOrderId) lastOrderId = o.getOrderId();
    }

    lastInvoiceId = 0;
    for (const auto& inv : invoices) {
        if (inv.getInvoiceId() > lastInvoiceId) lastInvoiceId = inv.getInvoiceId();
    }

    lastPromoId = 0;
    for (const auto& p : promotions) {
        if (p.getPromoId() > lastPromoId) lastPromoId = p.getPromoId();
    }

    auto itemsMap = FileManager::readOrderItems("data/order_items.txt", products);
    for (auto& order : orders) {
        int oid = order.getOrderId();
        if (itemsMap.count(oid)) {
            for (const auto& item : itemsMap[oid]) {
                order.addOrderItem(item);
            }
        }
    }

    auto stockMap = FileManager::readInventoryStock("data/inventory_stock.txt");
    for (auto& product : products) {
        int prodId = product.getProductId();
        if (stockMap.find(prodId) != stockMap.end()) {
            int sizeId = 1;
            for (const auto& [sizeName, quantity] : stockMap[prodId]) {
                Size size(sizeId++, sizeName, quantity);
                product.addSize(size);
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
    for (const auto& order : orders) if (order.getStatus() == "Completed") total += order.getTotalAmount();
    return total;
}

double ShopSystem::getRevenueThisMonth() const {
    double monthlyTotal = 0;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentMonth = 1 + ltm->tm_mon; 
    int currentYear = 1900 + ltm->tm_year;

    for (const auto& order : orders) {
        if (order.getStatus() == "Completed") {
            time_t orderDate = order.getOrderDate();
            tm* ltmOrder = localtime(&orderDate);
            if ((1 + ltmOrder->tm_mon) == currentMonth && (1900 + ltmOrder->tm_year) == currentYear) {
                 monthlyTotal += order.getTotalAmount();
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

vector<Product> ShopSystem::searchProducts(int categoryId, string keyword, long long minPrice, long long maxPrice, SortOption sortOption) {
    vector<Product> result;
    QString qKeyword = QString::fromStdString(keyword);

    for (const auto& p : products) {
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

    if (sortOption == PRICE_ASC) {
        std::sort(result.begin(), result.end(), [](const Product& a, const Product& b) { return a.getPrice() < b.getPrice(); });
    } else if (sortOption == PRICE_DESC) {
        std::sort(result.begin(), result.end(), [](const Product& a, const Product& b) { return a.getPrice() > b.getPrice(); });
    }

    return result;
}

string ShopSystem::validateCartStock() {
    string message = "";
    vector<int> itemsToRemove;
    auto& cartItems = currentCart.getItems();

    for (size_t i = 0; i < cartItems.size(); ++i) {
        CartItem& item = cartItems[i];
        int prodId = item.getProduct().getProductId();
        string sizeName = item.getSelectedSize();
        int currentQty = item.getQuantity();

        Product* realProd = findProduct(prodId);
        // th1: sản phẩm đã bị xóa khỏi hệ thống
        if (!realProd) {
            message += "- '" + item.getProduct().getName() + "' không còn kinh doanh -> Đã xóa khỏi giỏ.\n";
            itemsToRemove.push_back(i);
            continue;
        }

        //th2: size hết hàng hoặc không đủ số lượng
        Size* realSize = realProd->findSize(sizeName);
        int realStock = (realSize) ? realSize->getQuantity() : 0;

        if (realStock == 0) {
            message += "- '" + realProd->getName() + " (" + sizeName + ")' đã hết hàng -> Đã xóa khỏi giỏ.\n";
            itemsToRemove.push_back(i);
        }
        else if (currentQty > realStock) {
            item.updateQuantity(realStock);
            message += "- '" + realProd->getName() + " (" + sizeName + ")' chỉ còn " + to_string(realStock) + " cái -> Đã cập nhật lại số lượng.\n";
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

    orders.erase(remove_if(orders.begin(), orders.end(), [deletedId](const Order& o){ return o.getCustomerId() == deletedId; }), orders.end());
    reviews.erase(remove_if(reviews.begin(), reviews.end(), [deletedId](const Review& r){ return r.getCustomerId() == deletedId; }), reviews.end());
    savedUserCarts.erase(deletedId);

    logout();

    customers.erase(
        std::remove_if(customers.begin(), customers.end(), [deletedId](const Customer& c) { return c.getUserId() == deletedId; }),
        customers.end()
        );

    saveAllData();
}

int ShopSystem::getNewUserId() {
    lastUserId++;
    return lastUserId;
}

int ShopSystem::getNewProductId() {
    lastProductId++;
    return lastProductId;
}

int ShopSystem::getNewCategoryId() {
    lastCategoryId++;
    return lastCategoryId;
}

int ShopSystem::getNewOrderId() {
    lastOrderId++;
    return lastOrderId;
}

int ShopSystem::getNewInvoiceId() {
    lastInvoiceId++;
    return lastInvoiceId;
}

int ShopSystem::getNewPromoId() {
    lastPromoId++;
    return lastPromoId;
}

void ShopSystem::staffConfirmCancelOrder(int orderId) {
    Order* order = findOrder(orderId);
    if (!order) return;

    string oldStatus = order->getStatus();
    if (oldStatus == "Cancelled") return;

    for (const auto& item : order->getItems()) {
        Product* p = findProduct(item.getProduct().getProductId());
        if (p) p->updateStock(item.getSelectedSize(), item.getQuantity());
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
    for (const auto& [userId, cartItems] : savedUserCarts) {
        for (const auto& item : cartItems) {
            if (item.getProduct().getProductId() == productId && item.getSelectedSize() == sizeName) {
                total += item.getQuantity();
            }
        }
    }
    for (const auto& item : currentCart.getItems()) {
        if (item.getProduct().getProductId() == productId && item.getSelectedSize() == sizeName) {
            total += item.getQuantity();
        }
    }
    return total;
}

vector<Promotion>& ShopSystem::getPromotions() {
    return this->promotions;
}
void ShopSystem::removeReview(int reviewId) {
    for (auto it = reviews.begin(); it != reviews.end(); ++it) {
        if (it->getReviewId() == reviewId) {
            reviews.erase(it);
            return;
        }
    }
}
