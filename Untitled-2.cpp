#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    string name;
    int studentID;
    Student* next;
    
    Student(string n, int id) : name(n), studentID(id), next(nullptr) {}
};

class TShirtQueue {
private:
    Student* front;
    Student* rear;
    int size;
    int tshirtsAvailable;
    
public:
    TShirtQueue() : front(nullptr), rear(nullptr), size(0), tshirtsAvailable(100) {}
    
    bool isEmpty() {
        return front == nullptr;
    }
    
    void addStudent() {
        if (size >= tshirtsAvailable) {
            cout << "\n❌ No more T-shirts available! Queue full." << endl;
            return;
        }
        
        string name;
        int id;
        
        cout << "\n👤 Enter student name: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "🆔 Enter student ID: ";
        while (!(cin >> id) || id <= 0) {
            cout << "❌ Invalid ID! Enter a positive number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        
        if (findStudent(id)) {
            cout << "❌ Student ID already exists!" << endl;
            return;
        }
        
        Student* newStudent = new Student(name, id);
        
        if (isEmpty()) {
            front = rear = newStudent;
        } else {
            rear->next = newStudent;
            rear = newStudent;
        }
        
        size++;
        cout << "✅ " << name << " (ID: " << id << ") added to queue!" << endl;
    }
    
    void serveStudent() {
        if (isEmpty()) {
            cout << "\n❌ Queue is empty! No one to serve." << endl;
            return;
        }
        
        if (tshirtsAvailable <= 0) {
            cout << "\n❌ No T-shirts left!" << endl;
            return;
        }
        
        Student* served = front;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        
        cout << "\n🎁 Served: " << served->name << " (ID: " << served->studentID << ")" << endl;
        cout << "📦 T-shirts remaining: " << --tshirtsAvailable << endl;
        
        delete served;
        size--;
    }
    
    bool removeStudent(int id) {
        if (isEmpty()) {
            cout << "\n❌ Queue is empty!" << endl;
            return false;
        }
        
        if (front->studentID == id) {
            serveStudent();
            return true;
        }
        
        Student* current = front;
        Student* previous = nullptr;
        
        while (current != nullptr && current->studentID != id) {
            previous = current;
            current = current->next;
        }
        
        if (current == nullptr) {
            cout << "\n❌ Student ID " << id << " not found!" << endl;
            return false;
        }
        
        previous->next = current->next;
        if (current == rear) {
            rear = previous;
        }
        
        cout << "\n👋 " << current->name << " (ID: " << id << ") removed from queue." << endl;
        delete current;
        size--;
        return true;
    }
    
    bool findStudent(int id) {
        Student* current = front;
        while (current != nullptr) {
            if (current->studentID == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    void displayQueue() {
        if (isEmpty()) {
            cout << "\n📭 Queue is empty!" << endl;
            return;
        }
        
        cout << "\n📋 Current Queue (Front → Back):" << endl;
        Student* current = front;
        int position = 1;
        
        while (current != nullptr) {
            cout << position << ". " << current->name << " (ID: " << current->studentID << ")" << endl;
            current = current->next;
            position++;
        }
        cout << "👥 Total waiting: " << size << endl;
    }
    
    void countStudents() {
        cout << "\n👥 Total students waiting: " << size << endl;
        cout << "👕 T-shirts remaining: " << tshirtsAvailable << endl;
    }
    
    void checkTshirts() {
        cout << "\n👕 T-shirts remaining: " << tshirtsAvailable << endl;
        cout << "👥 Students in queue: " << size << endl;
    }
    
    ~TShirtQueue() {
        while (!isEmpty()) {
            serveStudent();
        }
    }
};

int main() {
    TShirtQueue queue;
    int choice;
    
    cout << "🎉 Welcome to Code-a-Thon T-Shirt Queue Management System! 🎉" << endl;
    
    while (true) {
        cout << "\n" << string(60, '=') << endl;
        cout << "📋 MENU OPTIONS:" << endl;
        cout << "1. ➕ Add Student" << endl;
        cout << "2. 🎁 Serve Student (Give T-shirt)" << endl;
        cout << "3. ❌ Remove Student by ID" << endl;
        cout << "4. 📋 Display Queue" << endl;
        cout << "5. 👥 Count Students" << endl;
        cout << "6. 👕 Check T-shirts Left" << endl;
        cout << "0. 🚪 Exit" << endl;
        cout << string(60, '=') << endl;
        cout << "Enter choice: ";
        
        while (!(cin >> choice) || choice < 0 || choice > 6) {
            cout << "❌ Invalid choice! Enter 0-6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        
        switch (choice) {
            case 1:
                queue.addStudent();
                break;
            case 2:
                queue.serveStudent();
                break;
            case 3: {
                int id;
                cout << "Enter student ID to remove: ";
                while (!(cin >> id) || id <= 0) {
                    cout << "❌ Invalid ID! Enter positive number: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                queue.removeStudent(id);
                break;
            }
            case 4:
                queue.displayQueue();
                break;
            case 5:
                queue.countStudents();
                break;
            case 6:
                queue.checkTshirts();
                break;
            case 0:
                cout << "\n👋 Thanks for managing the Code-a-Thon queue! Event successful!" << endl;
                return 0;
            default:
                cout << "❌ Invalid option!" << endl;
        }
    }
    
}