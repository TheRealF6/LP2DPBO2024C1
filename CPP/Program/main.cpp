#include "Shirt.cpp"
#include <iostream>
#include <vector>
#include <algorithm>

void showData(const vector<Shirt>& daftarShirt)
{
    size_t idProductWidth = 2, nameWidth = 4, brandWidth = 5, priceWidth = 11, sizeWidth = 6, materialWidth = 5, genderWidth = 6, colorWidth = 5, sleeve_typeWidth = 12;

    for (const Shirt& member : daftarShirt) {
        idProductWidth = max(idProductWidth, to_string(member.getIdProduct()).length());
        nameWidth = max(nameWidth, member.getName().length());
        brandWidth = max(brandWidth, member.getBrand().length());
        priceWidth = max(priceWidth, to_string(member.getPrice()).length());
        sizeWidth = max(sizeWidth, member.getSize().length());
        materialWidth = max(materialWidth, member.getMaterial().length());
        genderWidth = max(genderWidth, member.getGender().length());
        colorWidth = max(colorWidth, member.getColor().length());
        sleeve_typeWidth = max(sleeve_typeWidth, member.getSleeve_Type().length());
    }

    cout << "+-" << string(idProductWidth, '-') << "-+-" << string(nameWidth, '-') << "-+-" << string(brandWidth, '-') << "-+-" << string(priceWidth, '-') << "-+-" << string(sizeWidth, '-') << "-+-" << string(materialWidth, '-') << "-+-" << string(genderWidth, '-') << "-+-" << string(colorWidth, '-') << "-+-" << string(sleeve_typeWidth, '-') << "-+" << endl;
    printf("| %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s | %-*s |\n", idProductWidth, "ID", nameWidth, "Nama", brandWidth, "Merek", priceWidth, "Harga (Rp.)", sizeWidth, "Ukuran", materialWidth, "Bahan", genderWidth, "Gender", colorWidth, "Warna", sleeve_typeWidth, "Jenis Lengan");
    cout << "+-" << string(idProductWidth, '-') << "-+-" << string(nameWidth, '-') << "-+-" << string(brandWidth, '-') << "-+-" << string(priceWidth, '-') << "-+-" << string(sizeWidth, '-') << "-+-" << string(materialWidth, '-') << "-+-" << string(genderWidth, '-') << "-+-" << string(colorWidth, '-') << "-+-" << string(sleeve_typeWidth, '-') << "-+" << endl;

    for (const Shirt& member : daftarShirt) {
        printf("| %-*d | %-*s | %-*s | %-*d | %-*s | %-*s | %-*s | %-*s | %-*s |\n", idProductWidth, member.getIdProduct(), nameWidth, member.getName().c_str(), brandWidth, member.getBrand().c_str(), priceWidth, member.getPrice(), sizeWidth, member.getSize().c_str(), materialWidth, member.getMaterial().c_str(), genderWidth, member.getGender().c_str(), colorWidth, member.getColor().c_str(), sleeve_typeWidth, member.getSleeve_Type().c_str());
    }

    cout << "+-" << string(idProductWidth, '-') << "-+-" << string(nameWidth, '-') << "-+-" << string(brandWidth, '-') << "-+-" << string(priceWidth, '-') << "-+-" << string(sizeWidth, '-') << "-+-" << string(materialWidth, '-') << "-+-" << string(genderWidth, '-') << "-+-" << string(colorWidth, '-') << "-+-" << string(sleeve_typeWidth, '-') << "-+" << endl;
}

void addData(vector<Shirt>& daftarShirt)
{
    int newIdProduct;
    string newName, newBrand, newSize, newMaterial, newGender, newColor, newSleeve_Type;
    int newPrice;

    cout << "Masukkan ID produk: ";
    cin >> newIdProduct;
    cin.ignore();

    // Mengecek jika ada ID ada atau tidak (untuk kasus ini ID duplikat)
    bool idExists = any_of(daftarShirt.begin(), daftarShirt.end(), [&](const Shirt& shirt)
    {
        return shirt.getIdProduct() == newIdProduct;
    });
    if (idExists)
    {
        cout << "ID produk sudah ada dalam daftar. Tidak dapat menambahkan data baru." << endl;
        return;
    }

    cout << "Masukkan nama: ";
    getline(cin, newName);

    cout << "Masukkan merek: ";
    getline(cin, newBrand);

    cout << "Masukkan harga: ";
    cin >> newPrice;
    cin.ignore();

    cout << "Masukkan ukuran: ";
    getline(cin, newSize);

    cout << "Masukkan bahan: ";
    getline(cin, newMaterial);

    cout << "Masukkan gender: ";
    getline(cin, newGender);

    cout << "Masukkan warna: ";
    getline(cin, newColor);

    cout << "Masukkan jenis lengan: ";
    getline(cin, newSleeve_Type);

    daftarShirt.push_back(Shirt(newIdProduct, newName, newBrand, newPrice, newSize, newMaterial, newGender, newColor, newSleeve_Type));
    sort(daftarShirt.begin(), daftarShirt.end(), [](const Shirt& a, const Shirt& b)
    {
        return a.getIdProduct() < b.getIdProduct();
    });
    cout << "Data kemeja berhasil ditambah." << endl;
}

void updateData(vector<Shirt>& daftarShirt)
{
    int idProductToEdit;
    string newName, newBrand, newSize, newMaterial, newGender, newColor, newSleeve_Type;
    int newPrice;

    cout << "Masukkan ID produk kemeja yang ingin diperbarui: ";
    cin >> idProductToEdit;
    cin.ignore();

    // Mengecek jika ada ID ada atau tidak (untuk kasus ini ada tidaknya ID)
    bool idExists = any_of(daftarShirt.begin(), daftarShirt.end(), [&](const Shirt& shirt)
    {
        return shirt.getIdProduct() == idProductToEdit;
    });
    if (!idExists)
    {
        cout << "ID produk kemeja tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan nama: ";
    getline(cin, newName);

    cout << "Masukkan merek: ";
    getline(cin, newBrand);

    cout << "Masukkan harga: ";
    cin >> newPrice;
    cin.ignore();

    cout << "Masukkan ukuran: ";
    getline(cin, newSize);

    cout << "Masukkan bahan: ";
    getline(cin, newMaterial);

    cout << "Masukkan gender: ";
    getline(cin, newGender);

    cout << "Masukkan warna: ";
    getline(cin, newColor);

    cout << "Masukkan jenis lengan: ";
    getline(cin, newSleeve_Type);

    for (Shirt& member : daftarShirt) {
        if (member.getIdProduct() == idProductToEdit) {
            member.setName(newName);
            member.setBrand(newBrand);
            member.setPrice(newPrice);
            member.setSize(newSize);
            member.setMaterial(newMaterial);
            member.setGender(newGender);
            member.setColor(newColor);
            member.setSleeve_Type(newSleeve_Type);
            cout << "Data anggota berhasil diubah." << endl;
            return;
        }
    }
    cout << "Data kemeja berhasil diperbarui." << endl;
}

void deleteData(vector<Shirt>& daftarShirt)
{
    int idProductToDelete;

    cout << "Masukkan ID produk kemeja yang ingin dihapus: ";
    cin >> idProductToDelete;
    cin.ignore();

    for (auto it = daftarShirt.begin(); it != daftarShirt.end(); )
    {
        if (it->getIdProduct() == idProductToDelete)
        {
            it = daftarShirt.erase(it);
            cout << "Data anggota berhasil dihapus." << endl;
            return;
        }
        else
        {
            ++it;
        }
    }
    cout << "ID anggota tidak ditemukan." << endl;
}

int main()
{
    cout << "Selamat datang di Program Manajemen Produk Kemeja!" << endl;

    vector<Shirt> daftarShirt = {
        Shirt(1, "Long Long Int", "ShirtSkrrt", 150000, "L", "Katun", "Laki-laki", "Putih", "Panjang"),
        Shirt(2, "Alok451", "FreeKaus", 25000, "S", "Polyester", "Laki-laki", "Hitam", "Pendek"),
        Shirt(3, "No. 1", "Serial", 345000, "M", "Flanel", "Unisex", "Merah", "Panjang"),
        Shirt(4, "OldJeans", "K-Shirt", 670000, "XL", "Denim", "Perempuan", "Biru Tua", "Panjang"),
        Shirt(5, "Jawa", "Asli Indonesia", 79000, "L", "Linen", "Unisex", "Coklat", "Pendek"),
        Shirt(6, "TheJumat", "Berkah Shirt", 55000, "M", "Rayon", "Laki-laki", "Krem", "Panjang"),
        Shirt(7, "Queeness", "Femilope", 212000, "S", "Sutra", "Perempuan", "Pink", "Panjang")
    };

    showData(daftarShirt);

    string command;
    do
    {
        cout << "\nDaftar perintah:\n1. SHOW (Menampilkan data)\n2. ADD (Menambah data)\n3. UPDATE (Mengubah data)\n4. DELETE (Menghapus data)\n5. CLOSE (Menutup program)\n\nMasukkan perintah: ";
        getline(cin, command);
        transform(command.begin(), command.end(), command.begin(), ::toupper);
        if (command == "SHOW")
        {
            printf("\n");
            showData(daftarShirt);
        }
        else if (command == "ADD")
        {
            printf("\n");
            addData(daftarShirt);
        }
        else if (command == "UPDATE")
        {
            printf("\n");
            updateData(daftarShirt);
        }
        else if (command == "DELETE")
        {
            printf("\n");
            deleteData(daftarShirt);
        }
        else if (command != "CLOSE")
        {
            printf("\n");
            cout << "Perintah tidak valid." << endl;
        }
    }
    while (command != "CLOSE");

    cout << "\nProgram ditutup. Terima kasih!" << endl;

    return 0;
}