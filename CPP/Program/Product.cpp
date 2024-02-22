#include <string>

using namespace std;

class Product
{
    private:
        int idProduct;
        string name;
        string brand;
        int price;

    public:
        /* Constructor */
        Product()
        {
            this->idProduct = 0;
            this->name = "";
            this->brand = "";
            this->price = 0;
        }

        Product(int idProduct, string name, string brand, int price)
        {
            this->idProduct = idProduct;
            this->name = name;
            this->brand = brand;
            this->price = price;
        }

        int getIdProduct() const
        {
            return idProduct;
        }
        void setIdProduct(int idProduct)
        {
            this->idProduct = idProduct;
        }

        string getName() const
        {
            return name;
        }
        void setName(string name)
        {
            this->name = name;
        }

        string getBrand() const
        {
            return brand;
        }
        void setBrand(string brand)
        {
            this->brand = brand;
        }

        int getPrice() const
        {
            return price;
        }
        void setPrice(int price)
        {
            this->price = price;
        }

        /* Destructor */
        ~Product()
        {
            
        }
};
