class Product:
    def __init__(self, id_product, name, brand, price):
        self.id_product = id_product
        self.name = name
        self.brand = brand
        self.price = price

    def get_id_product(self):
        return self.id_product

    def set_id_product(self, id_product):
        self.id_product = id_product

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name

    def get_brand(self):
        return self.brand

    def set_brand(self, brand):
        self.brand = brand

    def get_price(self):
        return self.price

    def set_price(self, price):
        self.price = price
