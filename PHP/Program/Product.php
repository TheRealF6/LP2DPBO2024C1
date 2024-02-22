<?php

class Product {
    private $idProduct;
    private $name;
    private $brand;
    private $price;

    public function __construct($idProduct, $name, $brand, $price) {
        $this->idProduct = $idProduct;
        $this->name = $name;
        $this->brand = $brand;
        $this->price = $price;
    }

    public function getIdProduct() {
        return $this->idProduct;
    }
    public function setIdProduct($idProduct) {
        $this->idProduct = $idProduct;
    }

    public function getName() {
        return $this->name;
    }
    public function setName($name) {
        $this->name = $name;
    }

    public function getBrand() {
        return $this->brand;
    }
    public function setBrand($brand) {
        $this->brand = $brand;
    }

    public function getPrice() {
        return $this->price;
    }
    public function setPrice($price) {
        $this->price = $price;
    }
}

?>
