#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
        int productId;
        string itemName;
        float unitPrice;
        int quantity;

    public:
        void setProductId(int productID) { this->productId = productID; }
        void setItemName(string itemName) { this->itemName = itemName; }
        void setUnitePrice(float unitPrice) { this->unitPrice = unitPrice; }
        void setQuantity(int quantity) { this->quantity = quantity; };

        int getProductId() { return productId; }
        string getItemName() { return itemName; }
        float getUnitPrice() { return unitPrice; }
        int getQuantity() { return quantity; }

        void print() {
            cout << "Product Id: "<<  productId << endl;
            cout << "Item Name: "<< itemName << endl;
            cout << "Unit Price: "<< unitPrice << endl;
            cout << "Quantity: "<< quantity << endl;
            cout << "----------------------------------------------------" << endl;
        }


};

class Shop{
    private:
        int index = 0;
        int size;
        string name;
        Product* product;

    public:
        void initializeProduct(int size) {
            this->size = size;
            product = new Product[size];
        }
        void addProduct(Product product) {
            if (index < size) {
                this->product[index] = product;
                index++;
            }
        }
        void print(int productID){
            for (int i=0; i<index; i++) {
                if (product[i].getProductId() == productID)
                    product[i].print();
            }
        }
        void release() { delete[] product; }


};

int main() {
    Product product1;
    product1.setProductId(1);
    product1.setItemName("One");
    product1.setUnitePrice(100);
    product1.setQuantity(10);

    Product product2;
    product2.setProductId(2);
    product2.setItemName("Two");
    product2.setUnitePrice(200);
    product2.setQuantity(20);

    Shop shop;
    shop.initializeProduct(100);
    shop.addProduct(product1);
    shop.addProduct(product2);
    shop.print(1);
    shop.print(2);
    shop.release();

    return 0;
}