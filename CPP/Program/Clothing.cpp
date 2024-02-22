#include "Product.cpp"

class Clothing : public Product
{
    private:
        string size;
        string material;
        string gender;
    
    public:
        /* Constructor */
        Clothing()
        {
            this->size = "";
            this->material = "";
            this->gender = "";
        }

        Clothing(int idProduct, string name, string brand, int price, string size, string material, string gender) : Product(idProduct, name, brand, price)
        {
            this->size = size;
            this->material = material;
            this->gender = gender;
        }

        string getSize() const
        {
            return size;
        }
        void setSize(string size)
        {
            this->size = size;
        }

        string getMaterial() const
        {
            return material;
        }
        void setMaterial(string material)
        {
            this->material = material;
        }

        string getGender() const
        {
            return gender;
        }
        void setGender(string gender)
        {
            this->gender = gender;
        }

        /* Destructor */
        ~Clothing()
        {
            
        }
};