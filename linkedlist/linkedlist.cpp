#include <iostream>
using namespace std;

// Düğüm sınıfı
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Bağlı Liste sınıfı
class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    // Yeni düğüm ekleme
    void ekle(int value) {
        Node* yeniNode = new Node(value);
        
        if (head == nullptr) {
            head = yeniNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = yeniNode;
    }
    
    // Listeyi yazdırma
    void yazdir() {
        Node* temp = head;
        cout << "Liste: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Recursive sıralama için yardımcı fonksiyon
    Node* siralaRecursive(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
            
        Node* min = head;
        Node* temp = head->next;
        
        while (temp != nullptr) {
            if (temp->data < min->data)
                min = temp;
            temp = temp->next;
        }
        
        if (min != head) {
            int tempData = head->data;
            head->data = min->data;
            min->data = tempData;
        }
        
        head->next = siralaRecursive(head->next);
        return head;
    }
    
    // Recursive sıralama
    void sirala() {
        head = siralaRecursive(head);
    }
    
    // Yıkıcı fonksiyon - bellek temizleme
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList liste;
    int sayi;
    char devam;
    
    do {
        cout << "Bir sayi girin: ";
        cin >> sayi;
        liste.ekle(sayi);
        
        cout << "Baska sayi eklemek ister misiniz? (E/H): ";
        cin >> devam;
    } while (devam == 'E' || devam == 'e');
    
    cout << "\nSiralamadan önce ";
    liste.yazdir();
    
    liste.sirala();
    cout << "Siralamadan sonra ";
    liste.yazdir();
    
    return 0;
}
