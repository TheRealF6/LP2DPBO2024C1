import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

    static void showData(ArrayList<Shirt> daftarShirt) {
        int idProductWidth = 2, nameWidth = 4, brandWidth = 5, priceWidth = 11, sizeWidth = 6, materialWidth = 5, genderWidth = 6, colorWidth = 5, sleeve_typeWidth = 12;

        for (Shirt member : daftarShirt) {
            idProductWidth = Math.max(idProductWidth, String.valueOf(member.getIdProduct()).length());
            nameWidth = Math.max(nameWidth, member.getName().length());
            brandWidth = Math.max(brandWidth, member.getBrand().length());
            priceWidth = Math.max(priceWidth, String.valueOf(member.getPrice()).length());
            sizeWidth = Math.max(sizeWidth, member.getSize().length());
            materialWidth = Math.max(materialWidth, member.getMaterial().length());
            genderWidth = Math.max(genderWidth, member.getGender().length());
            colorWidth = Math.max(colorWidth, member.getColor().length());
            sleeve_typeWidth = Math.max(sleeve_typeWidth, member.getSleeve_type().length());
        }

        System.out.println("+-" + "-".repeat(idProductWidth) + "-+-" + "-".repeat(nameWidth) + "-+-" + "-".repeat(brandWidth) + "-+-" + "-".repeat(priceWidth) + "-+-" + "-".repeat(sizeWidth) + "-+-" + "-".repeat(materialWidth) + "-+-" + "-".repeat(genderWidth) + "-+-" + "-".repeat(colorWidth) + "-+-" + "-".repeat(sleeve_typeWidth) + "-+");
        System.out.printf("| %-" + idProductWidth + "s | %-" + nameWidth + "s | %-" + brandWidth + "s | %-" + priceWidth + "s | %-" + sizeWidth + "s | %-" + materialWidth + "s | %-" + genderWidth + "s | %-" + colorWidth + "s | %-" + sleeve_typeWidth + "s |\n", "ID", "Nama", "Merek", "Harga (Rp.)", "Ukuran", "Bahan", "Gender", "Warna", "Jenis Lengan");
        System.out.println("+-" + "-".repeat(idProductWidth) + "-+-" + "-".repeat(nameWidth) + "-+-" + "-".repeat(brandWidth) + "-+-" + "-".repeat(priceWidth) + "-+-" + "-".repeat(sizeWidth) + "-+-" + "-".repeat(materialWidth) + "-+-" + "-".repeat(genderWidth) + "-+-" + "-".repeat(colorWidth) + "-+-" + "-".repeat(sleeve_typeWidth) + "-+");

        for (Shirt member : daftarShirt) {
            System.out.printf("| %-" + idProductWidth + "d | %-" + nameWidth + "s | %-" + brandWidth + "s | %-" + priceWidth + "s | %-" + sizeWidth + "s | %-" + materialWidth + "s | %-" + genderWidth + "s | %-" + colorWidth + "s | %-" + sleeve_typeWidth + "s |\n", member.getIdProduct(), member.getName(), member.getBrand(), member.getPrice(), member.getSize(), member.getMaterial(), member.getGender(), member.getColor(), member.getSleeve_type());
        }

        System.out.println("+-" + "-".repeat(idProductWidth) + "-+-" + "-".repeat(nameWidth) + "-+-" + "-".repeat(brandWidth) + "-+-" + "-".repeat(priceWidth) + "-+-" + "-".repeat(sizeWidth) + "-+-" + "-".repeat(materialWidth) + "-+-" + "-".repeat(genderWidth) + "-+-" + "-".repeat(colorWidth) + "-+-" + "-".repeat(sleeve_typeWidth) + "-+");
    }

    static void addData(ArrayList<Shirt> daftarShirt) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Masukkan ID produk: ");
        int newIdProduct = scanner.nextInt();
        scanner.nextLine();

        boolean idExists = daftarShirt.stream().anyMatch(shirt -> shirt.getIdProduct() == newIdProduct);
        if (idExists) {
            System.out.println("ID produk sudah ada dalam daftar. Tidak dapat menambahkan data baru.");
            return; // Keluar dari method jika ID sudah ada
        }

        System.out.print("Masukkan nama: ");
        String newName = scanner.nextLine();

        System.out.print("Masukkan merek: ");
        String newBrand = scanner.nextLine();

        System.out.print("Masukkan harga: ");
        int newPrice = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Masukkan ukuran: ");
        String newSize = scanner.nextLine();

        System.out.print("Masukkan bahan: ");
        String newMaterial = scanner.nextLine();

        System.out.print("Masukkan gender: ");
        String newGender = scanner.nextLine();

        System.out.print("Masukkan warna: ");
        String newColor = scanner.nextLine();

        System.out.print("Masukkan jenis lengan: ");
        String newSleeve_type = scanner.nextLine();

        daftarShirt.add(new Shirt(newIdProduct, newName, newBrand, newPrice, newSize, newMaterial, newGender, newColor, newSleeve_type));
        Collections.sort(daftarShirt, Comparator.comparingInt(Shirt::getIdProduct));
        System.out.println("Data kemeja berhasil ditambah.");
    }

    static void updateData(ArrayList<Shirt> daftarShirt) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Masukkan ID produk kemeja yang ingin diubah: ");
        int idProductToEdit = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Masukkan nama: ");
        String newName = scanner.nextLine();

        System.out.print("Masukkan merek: ");
        String newBrand = scanner.nextLine();

        System.out.print("Masukkan harga: ");
        int newPrice = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Masukkan ukuran: ");
        String newSize = scanner.nextLine();

        System.out.print("Masukkan bahan: ");
        String newMaterial = scanner.nextLine();

        System.out.print("Masukkan gender: ");
        String newGender = scanner.nextLine();

        System.out.print("Masukkan warna: ");
        String newColor = scanner.nextLine();

        System.out.print("Masukkan jenis lengan: ");
        String newSleeve_type = scanner.nextLine();
        
        boolean found = false;
        for (Shirt member : daftarShirt) {
            if (member.getIdProduct() == idProductToEdit) {
                member.setName(newName);
                member.setBrand(newBrand);
                member.setPrice(newPrice);
                member.setSize(newSize);
                member.setMaterial(newMaterial);
                member.setGender(newGender);
                member.setColor(newColor);
                member.setSleeve_type(newSleeve_type);
                System.out.println("Data kemeja berhasil diubah.");
                found = true;
                break; // Keluar dari loop setelah menemukan anggota dengan ID yang sesuai
            }
        }
        if (!found) {
            System.out.println("ID produk kemeja tidak ditemukan.");
        }
    }

    static void deleteData(ArrayList<Shirt> daftarShirt) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Masukkan ID produk kemeja yang ingin dihapus: ");
        int idProductToDelete = scanner.nextInt();
        for (int i = 0; i < daftarShirt.size(); i++) {
            if (daftarShirt.get(i).getIdProduct() == idProductToDelete) {
                daftarShirt.remove(i);
                System.out.println("Data anggota berhasil dihapus.");
                return;
            }
        }
        System.out.println("ID anggota tidak ditemukan.");
    }

    public static void main(String[] args) {
        System.out.println("Selamat datang di Program Manajemen Produk Kemeja!");

        ArrayList<Shirt> daftarShirt = new ArrayList<>();
        daftarShirt.add(new Shirt(1, "Long Long Int", "ShirtSkrrt", 150000, "L", "Katun", "Laki-laki", "Putih", "Panjang"));
        daftarShirt.add(new Shirt(2, "Alok451", "FreeKaus", 25000, "S", "Polyester", "Laki-laki", "Hitam", "Pendek"));
        daftarShirt.add(new Shirt(3, "No. 1", "Serial", 345000, "M", "Flanel", "Unisex", "Merah", "Panjang"));
        daftarShirt.add(new Shirt(4, "OldJeans", "K-Shirt", 670000, "XL", "Denim", "Perempuan", "Biru Tua", "Panjang"));
        daftarShirt.add(new Shirt(5, "Jawa", "Asli Indonesia", 79000, "L", "Linen", "Unisex", "Coklat", "Pendek"));
        daftarShirt.add(new Shirt(6, "TheJumat", "Berkah Shirt", 55000, "M", "Rayon", "Laki-laki", "Krem", "Panjang"));
        daftarShirt.add(new Shirt(7, "Queeness", "Femilope", 212000, "S", "Sutra", "Perempuan", "Pink", "Panjang"));

        showData(daftarShirt);

        Scanner scanner = new Scanner(System.in);
        String command;
        do {
            System.out.print("\nDaftar perintah:\n1. SHOW (Menampilkan data)\n2. ADD (Menambah data)\n3. UPDATE (Mengubah data)\n4. DELETE (Menghapus data)\n5. CLOSE (Menutup program)\n\nMasukkan perintah: ");
            command = scanner.nextLine().toUpperCase();
            switch (command) {
                case "SHOW":
                    showData(daftarShirt);
                    break;
                case "ADD":
                    addData(daftarShirt);
                    break;
                case "UPDATE":
                    updateData(daftarShirt);
                    break;
                case "DELETE":
                    deleteData(daftarShirt);
                    break;
                case "CLOSE":
                    break;
                default:
                    System.out.println("Perintah tidak valid.");
            }
        } while (!command.equals("CLOSE"));

        System.out.println("Program ditutup. Terima kasih!");
    }
}
