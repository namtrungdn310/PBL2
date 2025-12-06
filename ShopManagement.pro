QT       += core gui widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
TARGET = ShopManagement
TEMPLATE = app

INCLUDEPATH += $$PWD/include \
               $$PWD/Widgets \
               $$PWD/Widgets/Customer \
               $$PWD/Widgets/Staff

SOURCES += \
    main.cpp \
    src/Cart.cpp src/CartItem.cpp src/Category.cpp src/Customer.cpp \
    src/FileManager.cpp src/Invoice.cpp src/Order.cpp src/OrderItem.cpp \
    src/Product.cpp src/Promotion.cpp src/Review.cpp src/ShopSystem.cpp \
    src/Size.cpp src/Staff.cpp src/User.cpp \
    \
    Widgets/MainWindow.cpp \
    Widgets/StartupWidget.cpp \
    Widgets/LoginWidget.cpp \
    Widgets/RegisterWidget.cpp \
    \
    Widgets/Customer/CustomerDashboard.cpp \
    Widgets/Customer/ViewProductsWidget.cpp \
    Widgets/Customer/ViewCartWidget.cpp \
    Widgets/Customer/OrderWidget.cpp \
    Widgets/Customer/OrderHistoryWidget.cpp \
    Widgets/Customer/PromotionsWidget.cpp \
    Widgets/Customer/ReviewsWidget.cpp \
    Widgets/Customer/AccountSettingsWidget.cpp \
    \
    Widgets/Staff/StaffDashboard.cpp \
    Widgets/Staff/EditCategoriesWidget.cpp \
    Widgets/Staff/EditProductsWidget.cpp \
    Widgets/Staff/EditPromotionsWidget.cpp \
    Widgets/Staff/EditReviewsWidget.cpp

HEADERS += \
    include/Cart.h include/CartItem.h include/Category.h include/Customer.h \
    include/FileManager.h include/Invoice.h include/Order.h include/OrderItem.h \
    include/Product.h include/Promotion.h include/Review.h include/ShopSystem.h \
    include/Size.h include/Staff.h include/User.h \
    \
    Widgets/MainWindow.h \
    Widgets/StartupWidget.h \
    Widgets/LoginWidget.h \
    Widgets/RegisterWidget.h \
    \
    Widgets/Customer/CustomerDashboard.h \
    Widgets/Customer/ViewProductsWidget.h \
    Widgets/Customer/ViewCartWidget.h \
    Widgets/Customer/OrderWidget.h \
    Widgets/Customer/OrderHistoryWidget.h \
    Widgets/Customer/PromotionsWidget.h \
    Widgets/Customer/ReviewsWidget.h \
    Widgets/Customer/AccountSettingsWidget.h \
    \
    Widgets/Staff/StaffDashboard.h \
    Widgets/Staff/EditCategoriesWidget.h \
    Widgets/Staff/EditProductsWidget.h \
    Widgets/Staff/EditPromotionsWidget.h \
    Widgets/Staff/EditReviewsWidget.h

FORMS += \
    Widgets/MainWindow.ui \
    Widgets/StartupWidget.ui \
    Widgets/LoginWidget.ui \
    Widgets/RegisterWidget.ui \
    \
    Widgets/Customer/CustomerDashboard.ui \
    Widgets/Customer/ViewProductsWidget.ui \
    Widgets/Customer/ViewCartWidget.ui \
    Widgets/Customer/OrderWidget.ui \
    Widgets/Customer/OrderHistoryWidget.ui \
    Widgets/Customer/PromotionsWidget.ui \
    Widgets/Customer/ReviewsWidget.ui \
    Widgets/Customer/AccountSettingsWidget.ui \
    \
    Widgets/Staff/StaffDashboard.ui \
    Widgets/Staff/EditCategoriesWidget.ui \
    Widgets/Staff/EditProductsWidget.ui \
    Widgets/Staff/EditPromotionsWidget.ui \
    Widgets/Staff/EditReviewsWidget.ui

RESOURCES += resources.qrc

DISTFILES += \
    data/customers.txt data/products.txt data/staff.txt \
    data/orders.txt data/promotions.txt data/reviews.txt \
    data/invoices.txt data/inventory_stock.txt \
    data/categories.txt data/carts.txt \
    data/order_items.txt
