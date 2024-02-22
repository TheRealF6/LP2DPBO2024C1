#include "Clothing.cpp"

class Shirt : public Clothing
{
    private:
        string color;
        string sleeve_type;
    
    public:
        /* Constructor */
        Shirt()
        {
            this->color = "";
            this->sleeve_type = "";
        }

        Shirt(int idProduct, string name, string brand, int price, string size, string material, string gender, string color, string sleeve_type) : Clothing(idProduct, name, brand, price, size, material, gender)
        {
            this->color = color;
            this->sleeve_type = sleeve_type;
        }

        string getColor() const
        {
            return color;
        }
        void setColor(string color)
        {
            this->color = color;
        }

        string getSleeve_Type() const
        {
            return sleeve_type;
        }
        void setSleeve_Type(string sleeve_type)
        {
            this->sleeve_type = sleeve_type;
        }

        /* Destructor */
        ~Shirt()
        {

        }
};