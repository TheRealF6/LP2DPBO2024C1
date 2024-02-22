<?php

require_once 'Shirt.php';

function showData($daftarShirt) {
    echo "<!DOCTYPE html>\n";
    echo "<html lang='en'>\n";
    echo "<head>\n";
    echo "<meta charset='UTF-8'>\n";
    echo "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n";
    echo "<title>Program Manajemen Produk Kemeja</title>\n";
    echo "</head>\n";
    echo "<body>\n";
    
    echo "<h1>Selamat datang di Program Manajemen Produk Kemeja!</h1>\n";
    echo "<table border='1'>\n";
    echo "<tr>\n";
    echo "<th>ID</th>\n";
    echo "<th>Nama</th>\n";
    echo "<th>Merek</th>\n";
    echo "<th>Harga (Rp.)</th>\n";
    echo "<th>Ukuran</th>\n";
    echo "<th>Bahan</th>\n";
    echo "<th>Gender</th>\n";
    echo "<th>Warna</th>\n";
    echo "<th>Jenis Lengan</th>\n";
    echo "</tr>\n";
    
    foreach ($daftarShirt as $shirt) {
        echo "<tr>\n";
        echo "<td>{$shirt->getIdProduct()}</td>\n";
        echo "<td>{$shirt->getName()}</td>\n";
        echo "<td>{$shirt->getBrand()}</td>\n";
        echo "<td>{$shirt->getPrice()}</td>\n";
        echo "<td>{$shirt->getSize()}</td>\n";
        echo "<td>{$shirt->getMaterial()}</td>\n";
        echo "<td>{$shirt->getGender()}</td>\n";
        echo "<td>{$shirt->getColor()}</td>\n";
        echo "<td>{$shirt->getSleeveType()}</td>\n";
        echo "</tr>\n";
    }
    
    echo "</table>\n";
    echo "</body>\n";
    echo "</html>\n";
}

$daftarShirt = [
    new Shirt(1, "Integer", "CodeApparel", 320000, "L", "Katun", "Laki-laki", "Biru Langit", "Pendek"),
    new Shirt(2, "Archipelago", "Nusantara", 45000, "M", "Polyester", "Laki-laki", "Hijau Rumput", "Pendek"),
    new Shirt(3, "Megacloudy", "NeoBatik", 125000, "L", "Katun", "Unisex", "Merah Marun", "Panjang"),
    new Shirt(4, "OldJeans", "K-Shirt", 670000, "XL", "Denim", "Perempuan", "Biru Tua", "Panjang"),
    new Shirt(5, "Telur Asin", "EGG", 181000, "L", "Katun", "Laki-laki", "Biru Telur Asin", "Pendek"),
    new Shirt(6, "J.U.M.A.T", "Berkah Shirt", 55000, "M", "Polyester", "Laki-laki", "Krem Muda", "Panjang"),
    new Shirt(7, "Best Asset No.1", "LethalShirt", 1111000, "XL", "Katun", "Unisex", "Merah Darah", "Pendek"),
    new Shirt(8, "Democracy", "Freedom Diver", 177600, "L", "Polyester", "Unisex", "Kuning Emas", "Pendek"),
    new Shirt(9, "Crystalline", "Violetta", 979000, "M", "Sutra", "Perempuan", "Ungu Lavender", "Panjang"),
    new Shirt(10, "Atlantica", "Estrella", 676000, "L", "Sutra", "Perempuan", "Biru Royal", "Panjang")
];

showData($daftarShirt);

?>
