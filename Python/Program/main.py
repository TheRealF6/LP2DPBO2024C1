from Shirt import Shirt

def show_data(daftar_shirt):
    id_width = 2
    name_width = 4
    brand_width = 5
    price_width = 11
    size_width = 6
    material_width = 5
    gender_width = 6
    color_width = 5
    sleeve_type_width = 12

    for shirt in daftar_shirt:
        id_width = max(id_width, len(str(shirt.get_id_product())))
        name_width = max(name_width, len(shirt.get_name()))
        brand_width = max(brand_width, len(shirt.get_brand()))
        price_width = max(price_width, len(str(shirt.get_price())))
        size_width = max(size_width, len(shirt.get_size()))
        material_width = max(material_width, len(shirt.get_material()))
        gender_width = max(gender_width, len(shirt.get_gender()))
        color_width = max(color_width, len(shirt.get_color()))
        sleeve_type_width = max(sleeve_type_width, len(shirt.get_sleeve_type()))
    

    print("+-" + "-"*id_width + "-+-" + "-"*name_width + "-+-" + "-"*brand_width + "-+-" + "-"*price_width + "-+-" + "-"*size_width + "-+-" + "-"*material_width + "-+-" + "-"*gender_width + "-+-" + "-"*color_width + "-+-" + "-"*sleeve_type_width + "-+")
    print("| {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} |".format("ID", id_width, "Nama", name_width, "Merek", brand_width, "Harga (Rp.)", price_width, "Ukuran", size_width, "Bahan", material_width, "Gender", gender_width, "Warna", color_width, "Jenis Lengan", sleeve_type_width))
    print("+-" + "-"*id_width + "-+-" + "-"*name_width + "-+-" + "-"*brand_width + "-+-" + "-"*price_width + "-+-" + "-"*size_width + "-+-" + "-"*material_width + "-+-" + "-"*gender_width + "-+-" + "-"*color_width + "-+-" + "-"*sleeve_type_width + "-+")

    for shirt in daftar_shirt:
        print("| {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} | {:<{}} |".format(shirt.get_id_product(), id_width, shirt.get_name(), name_width, shirt.get_brand(), brand_width, shirt.get_price(), price_width, shirt.get_size(), size_width, shirt.get_material(), material_width, shirt.get_gender(), gender_width, shirt.get_color(), color_width, shirt.get_sleeve_type(), sleeve_type_width))

    print("+-" + "-"*id_width + "-+-" + "-"*name_width + "-+-" + "-"*brand_width + "-+-" + "-"*price_width + "-+-" + "-"*size_width + "-+-" + "-"*material_width + "-+-" + "-"*gender_width + "-+-" + "-"*color_width + "-+-" + "-"*sleeve_type_width + "-+")


def add_data(daftar_shirt):
    id_product = int(input("Masukkan ID produk: "))
    name = input("Masukkan nama: ")
    brand = input("Masukkan merek: ")
    price = int(input("Masukkan harga: "))
    size = input("Masukkan ukuran: ")
    material = input("Masukkan bahan: ")
    gender = input("Masukkan gender: ")
    color = input("Masukkan warna: ")
    sleeve_type = input("Masukkan jenis lengan: ")
    daftar_shirt.append(Shirt(id_product, name, brand, price, size, material, gender, color, sleeve_type))
    print("Data kemeja berhasil ditambah.")

def update_data(daftar_shirt):
    id_product_to_update = int(input("Masukkan ID produk kemeja yang ingin diubah: "))
    for shirt in daftar_shirt:
        if shirt.get_id_product() == id_product_to_update:
            shirt.set_name(input("Masukkan nama: "))
            shirt.set_brand(input("Masukkan merek: "))
            shirt.set_price(int(input("Masukkan harga: ")))
            shirt.set_size(input("Masukkan ukuran: "))
            shirt.set_material(input("Masukkan bahan: "))
            shirt.set_gender(input("Masukkan gender: "))
            shirt.set_color(input("Masukkan warna: "))
            shirt.set_sleeve_type(input("Masukkan jenis lengan: "))
            print("Data kemeja berhasil diubah.")
            return
    print("ID produk kemeja tidak ditemukan.")

def delete_data(daftar_shirt):
    id_product_to_delete = int(input("Masukkan ID produk kemeja yang ingin dihapus: "))
    for i, shirt in enumerate(daftar_shirt):
        if shirt.get_id_product() == id_product_to_delete:
            del daftar_shirt[i]
            print("Data kemeja berhasil dihapus.")
            return
    print("ID produk kemeja tidak ditemukan.")

def main():
    print("Selamat datang di Program Manajemen Produk Kemeja!")

    daftar_shirt = [
        Shirt(1, "Long Long Int", "ShirtSkrrt", 150000, "L", "Katun", "Laki-laki", "Putih", "Panjang"),
        Shirt(2, "Alok451", "FreeKaus", 25000, "S", "Polyester", "Laki-laki", "Hitam", "Pendek"),
        Shirt(3, "No. 1", "Serial", 345000, "M", "Flanel", "Unisex", "Merah", "Panjang"),
        Shirt(4, "OldJeans", "K-Shirt", 670000, "XL", "Denim", "Perempuan", "Biru Tua", "Panjang"),
        Shirt(5, "Jawa", "Asli Indonesia", 79000, "L", "Linen", "Unisex", "Coklat", "Pendek"),
        Shirt(6, "TheJumat", "Berkah Shirt", 55000, "M", "Rayon", "Laki-laki", "Krem", "Panjang"),
        Shirt(7, "Queeness", "Femilope", 212000, "S", "Sutra", "Perempuan", "Pink", "Panjang")
    ]

    show_data(daftar_shirt)

    while True:
        command = input("\nDaftar perintah:\n1. SHOW (Menampilkan data)\n2. ADD (Menambah data)\n3. UPDATE (Mengubah data)\n4. DELETE (Menghapus data)\n5. CLOSE (Menutup program)\n\nMasukkan perintah: ").upper()

        if command == "SHOW":
            print("")
            show_data(daftar_shirt)
        elif command == "ADD":
            print("")
            add_data(daftar_shirt)
        elif command == "UPDATE":
            print("")
            update_data(daftar_shirt)
        elif command == "DELETE":
            print("")
            delete_data(daftar_shirt)
        elif command == "CLOSE":
            break
        else:
            print("")
            print("Perintah tidak valid.")

    print("\nProgram ditutup. Terima kasih!")

if __name__ == "__main__":
    main()
