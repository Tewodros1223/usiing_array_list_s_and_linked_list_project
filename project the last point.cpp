


#include <iostream>
#include <cstring>
#include<iomanip>
using namespace std;

struct Customer {
    char customer_name[100];
    int customer_id;
    char sex;
    int phone_number;
    int age;
};

struct Node {
    Customer data;
    Node* next;
};

// Linked List Functions

// Insert at the beginning of the Linked List
void insertAtBeginning(Node*& head, Customer customer) {
    Node* newNode = new Node;
    newNode->data = customer;
    newNode->next = head;
    head = newNode;
}

// Insert at the end of the Linked List
void insertAtEnd(Node*& head, Customer customer) {
    Node* newNode = new Node;
    newNode->data = customer;
    newNode->next = NULL;

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position in the Linked List
void insertAtPosition(Node*& head, Customer customer, int position) {
    Node* newNode = new Node;
    newNode->data = customer;

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "Position out of range\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node of the Linked List
void deleteAtBeginning(Node*& head) {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Delete the last node of the Linked List
void deleteAtEnd(Node*& head) {
    if (head) {
        if (!head->next) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
}

// Delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    if (!head) return;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (!temp || !temp->next) {
        cout << "Position out of range\n";
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Delete all nodes in the Linked List
void deleteAll(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Selection Sort by customer name (Linked List)
void selectionSort(Node* head) {
    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->data.customer_name, j->data.customer_name) > 0) {
                swap(i->data, j->data);
            }
        }
    }
}

// Bubble Sort by customer name (Linked List)
void bubbleSort(Node* head) {
    bool swapped;
    do {
        swapped = false;
        for (Node* temp = head; temp && temp->next; temp = temp->next) {
            if (strcmp(temp->data.customer_name, temp->next->data.customer_name) > 0) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
        }
    } while (swapped);
}

// Insertion Sort by customer name (Linked List)
void insertionSort(Node*& head) {
    if (!head) return;

    Node* sorted = NULL;
    Node* temp = head;

    while (temp) {
        Node* next = temp->next;
        if (!sorted || strcmp(sorted->data.customer_name, temp->data.customer_name) >= 0) {
            temp->next = sorted;
            sorted = temp;
        } else {
            Node* curr = sorted;
            while (curr->next && strcmp(curr->next->data.customer_name, temp->data.customer_name) < 0) {
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
        temp = next;
    }

    head = sorted;
}

// Linear Search by phone number (Linked List)
Node* linearSearch(Node* head, int phone_number) {
    Node* temp = head;
    while (temp) {
        if (temp->data.phone_number == phone_number)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Binary Search by phone number (Linked List)
Node* binarySearch(Node* head, int phone_number) {
    Node* temp = head;
    Node* arr[100];
    int i = 0;

    while (temp) {
        arr[i++] = temp;
        temp = temp->next;
    }

    int low = 0, high = i - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid]->data.phone_number == phone_number)
            return arr[mid];
        else if (arr[mid]->data.phone_number < phone_number)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return NULL;
}

// Display all customers (Linked List)
void display(Node* head) {
    Node* temp = head;
        cout<<left;
        cout<<setfill('-')<<setw(15)<<"Name"<<setw(12)<<"Id"<<setw(10)<<"sex"<<setw(15)<<"pho_no"<<setw(10)<<"age"<<endl;
    while (temp) {
        cout << setw(15) << temp->data.customer_name << setw(12) << temp->data.customer_id
             << setw(10)<< temp->data.sex << setw(15) << temp->data.phone_number
             << setw(10)<< temp->data.age << endl;
        temp = temp->next;
    }
}

// Array List Functions

// Insert at the beginning of the Array List
void insertAtBeginning(Customer arr[], int& size, Customer customer) {
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = customer;
    size++;
}

// Insert at the end of the Array List
void insertAtEnd(Customer arr[], int& size, Customer customer) {
    arr[size++] = customer;
}

// Insert at a specific position in the Array List
void insertAtPosition(Customer arr[], int& size, Customer customer, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid position\n";
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = customer;
    size++;
}

// Delete the first element of the Array List
void deleteAtBeginning(Customer arr[], int& size) {
    if (size == 0) return;
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Delete the last element of the Array List
void deleteAtEnd(Customer arr[], int& size) {
    if (size == 0) return;
    size--;
}

// Delete at a specific position in the Array List
void deleteAtPosition(Customer arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Delete all elements of the Array List
void deleteAll(Customer arr[], int& size) {
    size = 0;
}

// Selection Sort by customer name (Array List)
void selectionSortArray(Customer arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (strcmp(arr[j].customer_name, arr[minIdx].customer_name) < 0) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Bubble Sort by customer name (Array List)
void bubbleSortArray(Customer arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(arr[j].customer_name, arr[j + 1].customer_name) > 0) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Insertion Sort by customer name (Array List)
void insertionSortArray(Customer arr[], int size) {
    for (int i = 1; i < size; i++) {
        Customer key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].customer_name, key.customer_name) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Linear Search by phone number (Array List)
int linearSearchArray(Customer arr[], int size, int phone_number) {
    for (int i = 0; i < size; i++) {
        if (arr[i].phone_number == phone_number) {
            return i;
        }
    }
    return -1;
}

// Binary Search by phone number (Array List)
int binarySearchArray(Customer arr[], int size, int phone_number) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid].phone_number == phone_number) {
            return mid;
        }
        if (arr[mid].phone_number < phone_number) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Display all customers (Array List)
void displayArray(Customer arr[], int size) {
        cout<<left;
        cout<<setfill('-')<<setw(15)<<"Name"<<setw(10)<<"Id"<<setw(10)<<"sex"<<setw(15)<<"pho_no"<<setw(10)<<"age"<<endl;
    for (int i = 0; i < size; i++) {
        cout << setw(15) << arr[i].customer_name <<setw(10) << arr[i].customer_id
             << setw(10) << arr[i].sex << setw(15) << arr[i].phone_number
             << setw(10) << arr[i].age << endl;
    }
}

// Main program for menu-driven interface
int main() {
    cout << "DATA STRUCTURE AND ALGORITHM GROUP PROJECT" << endl;
    cout << "THIS PROJECT TITTLE IS CUSTOMER RELATIONSHIP MANAGEMEMT SYSTEM"  << endl;
    cout<<setfill('=')<<setw(20)<<endl;
    cout <<" GROUP MEMMBERS "<<endl;
    cout << left;
    cout<<"   "<<setfill('-')<<setw(27)<<"Name"<<"Id_num"<<endl;
    cout<<setw(27)<<"1 :Tewodros kassa"<<"01702 /15"<<endl;
    cout<<setw(27)<<"2 :Teklemariam Mihret"<<"01679 /15"<<endl;
    cout<<setw(27)<<"3 :Yohannes Haile"<<"02778 /15"<<endl;
    cout<<setw(27)<<"4 :Lielt Asnake"<<"02487 /15"<<endl;
    cout<<setw(27)<<"5 :Haymanot Belete"<<"02381 /15"<<endl;
    Node* linkedListHead = NULL;
    Customer arrayList[100];
    int linkedListSize = 0, arrayListSize = 0;
    int choice, position, phoneNumber, index;
    Customer tempCustomer;

    do {
        cout << "\nCustomer Management System\n";
        cout << "1. Linked List Operations\n";
        cout << "2. Array List Operations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Linked List Menu
            do {
                cout << "\nLinked List Operations\n";
                cout << "1. Insert Customer\n";
                cout << "2. Delete Customer\n";
                cout << "3. Sort Customers\n";
                cout << "4. Search Customer\n";
                cout << "5. Display Customer Data\n";
                cout << "6. Exit Linked List\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "\nInsert Customer at \n1) Begin \n2) End \n3) Position: "<<endl;
                    cout<<"enter your choice: ";
                    int option;
                    cin >> option;
                    cout << "Enter customer name: ";
                    cin >> tempCustomer.customer_name;
                    cout << "Enter customer ID: ";
                    cin >> tempCustomer.customer_id;
                    cout << "Enter customer sex (M/F): ";
                    cin >> tempCustomer.sex;
                    cout << "Enter customer phone number: ";
                    cin >> tempCustomer.phone_number;
                    cout << "Enter customer age: ";
                    cin >> tempCustomer.age;

                    if (option == 1) insertAtBeginning(linkedListHead, tempCustomer);
                    else if (option == 2) insertAtEnd(linkedListHead, tempCustomer);
                    else if (option == 3) {
                        cout << "Enter position: ";
                        cin >> position;
                        insertAtPosition(linkedListHead, tempCustomer, position);
                    }
                    break;

                case 2:
                    cout << "\nDelete Customer at \n1) Begin \n2) End \n3) Position \n4) All: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    if (option == 1) deleteAtBeginning(linkedListHead);
                    else if (option == 2) deleteAtEnd(linkedListHead);
                    else if (option == 3) {
                        cout << "Enter position: ";
                        cin >> position;
                        deleteAtPosition(linkedListHead, position);
                    }
                    else if (option == 4) deleteAll(linkedListHead);
                    break;

                case 3:
                    cout << "\nSort Customers by \n1) Selection Sort \n2) Bubble Sort \n3) Insertion Sort: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    if (option == 1) selectionSort(linkedListHead);
                    else if (option == 2) bubbleSort(linkedListHead);
                    else if (option == 3) insertionSort(linkedListHead);
                    break;

                case 4:
                    cout << "\nSearch Customer by \n1) Linear Search \n2) Binary Search: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    cout << "Enter customer phone number to search: ";
                    cin >> phoneNumber;
                    if (option == 1) {
                        Node* result = linearSearch(linkedListHead, phoneNumber);
                        if (result) cout << "Customer found: " << result->data.customer_name << endl;
                        else cout << "Customer not found.\n";
                    } else if (option == 2) {
                        Node* result = binarySearch(linkedListHead, phoneNumber);
                        if (result) cout << "Customer found: " << result->data.customer_name << endl;
                        else cout << "Customer not found.\n";
                    }
                    break;

                case 5:
                    cout << "\nDisplaying Customer Data:\n";
                    display(linkedListHead);
                    break;

                case 6:
                    cout << "Exiting Linked List Operations\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 6);
            break;

        case 2:
            // Array List Menu
            do {
                cout << "\nArray List Operations\n";
                cout << "1. Insert Customer\n";
                cout << "2. Delete Customer\n";
                cout << "3. Sort Customers\n";
                cout << "4. Search Customer\n";
                cout << "5. Display Customer Data\n";
                cout << "6. Exit Array List\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "\nInsert Customer at \n1) Begin \n2) End \n3) Position: "<<endl;
                    cout<<"enter your choice: ";
                    int option;
                    cin >> option;
                    cout << "Enter customer name: ";
                    cin >> tempCustomer.customer_name;
                    cout << "Enter customer ID: ";
                    cin >> tempCustomer.customer_id;
                    cout << "Enter customer sex (M/F): ";
                    cin >> tempCustomer.sex;
                    cout << "Enter customer phone number: ";
                    cin >> tempCustomer.phone_number;
                    cout << "Enter customer age: ";
                    cin >> tempCustomer.age;

                    if (option == 1) insertAtBeginning(arrayList, arrayListSize, tempCustomer);
                    else if (option == 2) insertAtEnd(arrayList, arrayListSize, tempCustomer);
                    else if (option == 3) {
                        cout << "Enter position: ";
                        cin >> position;
                        insertAtPosition(arrayList, arrayListSize, tempCustomer, position);
                    }
                    break;

                case 2:
                    cout << "\nDelete Customer at \n1) Begin \n2) End \n3) Position \n4) All: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    if (option == 1) deleteAtBeginning(arrayList, arrayListSize);
                    else if (option == 2) deleteAtEnd(arrayList, arrayListSize);
                    else if (option == 3) {
                        cout << "Enter position: ";
                        cin >> position;
                        deleteAtPosition(arrayList, arrayListSize, position);
                    }
                    else if (option == 4) deleteAll(arrayList, arrayListSize);
                    break;

                case 3:
                    cout << "\nSort Customers by \n1) Selection Sort \n2) Bubble Sort \n3) Insertion Sort: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    if (option == 1) selectionSortArray(arrayList, arrayListSize);
                    else if (option == 2) bubbleSortArray(arrayList, arrayListSize);
                    else if (option == 3) insertionSortArray(arrayList, arrayListSize);
                    break;

                case 4:
                    cout << "\nSearch Customer by \n1) Linear Search \n2) Binary Search: "<<endl;
                    cout<<"enter your choice: ";
                    cin >> option;
                    cout << "Enter customer phone number to search: ";
                    cin >> phoneNumber;
                    if (option == 1) {
                        index = linearSearchArray(arrayList, arrayListSize, phoneNumber);
                        if (index != -1) cout << "Customer found: " << arrayList[index].customer_name << endl;
                        else cout << "Customer not found.\n";
                    } else if (option == 2) {
                        index = binarySearchArray(arrayList, arrayListSize, phoneNumber);
                        if (index != -1) cout << "Customer found: " << arrayList[index].customer_name << endl;
                        else cout << "Customer not found.\n";
                    }
                    break;

                case 5:
                    cout << "\nDisplaying Customer Data:\n";
                    displayArray(arrayList, arrayListSize);
                    break;

                case 6:
                    cout << "Exiting Array List Operations\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
                }
            } while (choice != 6);
            break;

        case 3:
            cout << "Exiting Customer Management System\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}



