from Clothing import Clothing

class Shirt(Clothing):
    def __init__(self, id_product, name, brand, price, size, material, gender, color, sleeve_type):
        super().__init__(id_product, name, brand, price, size, material, gender)
        self.color = color
        self.sleeve_type = sleeve_type

    def get_color(self):
        return self.color

    def set_color(self, color):
        self.color = color

    def get_sleeve_type(self):
        return self.sleeve_type

    def set_sleeve_type(self, sleeve_type):
        self.sleeve_type = sleeve_type
