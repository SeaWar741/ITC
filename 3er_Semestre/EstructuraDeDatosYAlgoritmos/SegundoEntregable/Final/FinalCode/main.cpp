//Juan Carlos Garfias Tovar, A01652138
#include<iostream>
#include <new>
#include "Node.h"
//#include "Queue.h"
 
using namespace std;
 
//Clase Doubly linked list
class DoublyLinkedList {
  private:
    int size=0;
  public: 
    Node * head;

    //constructor default
    DoublyLinkedList() {
      head = NULL;
    }
    
    //constructor con nodo para head
    DoublyLinkedList(Node * n) {
      head = n;
    }

    //get size
    int getSize(){return size;};

    //Check if exists in list
    Node * nodeExists(int k) {
        Node * temp = NULL;
        Node * ptr = head;

        while (ptr != NULL) {
          if (ptr -> key == k) {
            temp = ptr;
          }
          ptr = ptr -> next;
        }

        return temp;
      }
  
    //Node at the end append
    void appendNode(Node * n) {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists"<< endl;
      } else {
        if (head == NULL) {
          head = n;
          //cout << "Node Appended as Head Node" << endl;
        } else {
          Node * ptr = head;
          while (ptr -> next != NULL) {
            ptr = ptr -> next;
          }
          ptr -> next = n;
          n -> previous = ptr;
          //cout << "Node Appended" << endl;
        }
        size++;
      }
    }
  
    //Node at the start append
    void prependNode(Node * n) {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists" << endl;
      } else {
        if (head == NULL) {
          head = n;
          //cout << "Node Prepended as Head Node" << endl;
        } else {
          head -> previous = n;
          n -> next = head;
          head = n;
          //cout << "Node Prepended" << endl;
        }
        size++;
  
      }
    }
  
    //Insert after key append
    void insertNodeAfter(int k, Node * n) {
      Node * ptr = nodeExists(k);
      if (ptr == NULL) {
        cout << "No node exists with key value: " << k << endl;
      } else {
        if (nodeExists(n -> key) != NULL) {
          //cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } else {
          Node * nextNode = ptr -> next;
          // inserting at the end
          if (nextNode == NULL) {
            ptr -> next = n;
            n -> previous = ptr;
            //cout << "Node Inserted at the END" << endl;
          }
  
          //inserting in between
          else {
            n -> next = nextNode;
            nextNode -> previous = n;
            n -> previous = ptr;
            ptr -> next = n;
  
            //cout << "Node Inserted in Between" << endl;
  
          }
          size++;
  
        }
      }
    }
  
    // Delete by key 
    void deleteNodeByKey(int k) {
      Node * ptr = nodeExists(k);
      if (ptr == NULL) {
        //cout << "No node exists with key value: " << k << endl;
      } else {
  
        if (head -> key == k) {
          head = head -> next;
          //cout << "Node UNLINKED with keys value : " << k << endl;
        } else {
          Node * nextNode = ptr -> next;
          Node * prevNode = ptr -> previous;
          // deleting at the end
          if (nextNode == NULL) {
  
            prevNode -> next = NULL;
            //cout << "Node Deleted at the END" << endl;
          }
  
          //deleting in between
          else {
            prevNode -> next = nextNode;
            nextNode -> previous = prevNode;
            //cout << "Node Deleted in Between" << endl;
  
          }
          size--;
        }
      }
    }
  
    //Update Noded
    void updateNodeByKey(int k, RegistryEntry d) {
      Node * ptr = nodeExists(k);
      if (ptr != NULL) {
        ptr -> data = d;
        //cout << "Node Data Updated Successfully" << endl;
      } else {
        //cout << "Node Doesn't exist with key value : " << k << endl;
      }
  
    }

    //get data by key
    RegistryEntry getData(int k){
      Node * ptr = nodeExists(k);
      RegistryEntry entry;
      if (ptr != NULL) {
        return ptr -> data;
        //cout << "Node Data Updated Successfully" << endl;
      } else {
        //cout << "Node Doesn't exist with key value : " << k << endl;
        return entry;
      }
    }

    // printing
    void printList() {
      if (head == NULL) {
        cout << "Empty List"<<endl;
      } else {
        Node * temp = head;
  
        while (temp != NULL) {
          printEntry(temp->data);
          temp = temp -> next;
        }
      }
 
    }

    //delete list
    void clear(int &key){
      while (key>=0){
        deleteNodeByKey(key);
        key--;
      }
    }
};


//-------------------------------------Sort functions---------------------------------

//Divide en dos listas
void splitList(Node *src, Node **fRef, Node **bRef){
   Node *fast;
   Node *slow;
   slow = src;
   fast = src->next;
   while (fast != NULL) {//itera y divide la lista en 2
      fast = fast->next;
      if (fast != NULL) {
         slow = slow->next;
         fast = fast->next;
      }
   }
   *fRef = src;
   *bRef = slow->next;
   slow->next = NULL;
}

//Funcion merge para merge sort a 
//partir de comparasion con fechas
Node *mergeSortedLists(Node *head1, Node *head2){
   Node *result = NULL;
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   //if (head1->data < head2->data) {
    if(head1->data.dateIsMinor(head2->data)){//compara si una fecha es menor o no
      head1->next = mergeSortedLists(head1->next, head2);
      head1->next->previous = head1;
      head1->previous = NULL;
      return head1;
   } else {//si no continua
      head2->next = mergeSortedLists(head1, head2->next);
      head2->next->previous = head2;
      head2->previous = NULL;
      return head2;
   }
}

//O(nlogn)
//Merge Sort 
void mergeSort(Node **head){//realiza el merge sort directamente a la lista a partir de los nodos
   Node *p = *head;
   Node *a = NULL;
   Node *b = NULL;
   if (p == NULL || p->next == NULL) {
      return;
   }
   splitList(p, &a, &b);
   mergeSort(&a);
   mergeSort(&b);
   *head = mergeSortedLists(a, b);
}


//------------------------------------Search Functions--------------------------------

struct Node* mid_node(Node* start, Node* last){
   if (start == NULL)
      return NULL;
   struct Node* slow = start;
   struct Node* fast = start -> next;
   while (fast != last){
      fast = fast -> next;
      if (fast != last){
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   return slow;
}

//O(log n)
//funcion binary search en lista
struct Node* binarySearch(Node *head, RegistryEntry &value){
  struct Node* start = head;
  struct Node* last = NULL;
  do{
    Node* mid = mid_node(start, last);
    if (mid == NULL)
      return NULL;
    if (mid -> data.dateIsEqual(value))//igual
      return mid;
    else if (mid -> data.dateIsMinor(value))//menor
      start = mid -> next;
    else
      last = mid;//mayor
  }
  while (last == NULL || last != start);
    return NULL;  
}

//Busqueda a partir de los limites
//O(n) dado el rango de busqueda
string search(DoublyLinkedList lista, RegistryEntry &value1, RegistryEntry &value2){
  Node* upper = binarySearch(lista.head,value1);
  Node* lower = binarySearch(lista.head,value2);
  //imprimir lista
  Node * temp = upper;

  string queryR="";

  while (temp != NULL && temp->previous!=lower) {
    printEntry(temp->data);
    queryR +=stringEntry(temp->data);
    temp = temp -> next;
    if(temp->next==lower->previous){
      break;
    }
  }
  return queryR;
}


//----------------------------------------Query--------------------------------------
//Funcion para hacer query de una fecha
void fetchQuery(DoublyLinkedList &list){
    time_t rawtime;
    struct tm * timeinfo; //Se obtiene la fecha actual del sistema y se formatea para nombre de archivo
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H-%M-%S",timeinfo);
    std::string str(buffer); //fecha a un string

    string lowerMonth,upperM,save,fetched;
    int lowerDay,upperDay,inputHourLower,inputHourUpper;
    bool continues = false;

    while(!continues){
        cout<<"Ingresa las primeras 3 letras del mes inicial >";cin>>lowerMonth;
        lowerMonth = monthFormater(lowerMonth);
        cout<<"Ingresa el dia del mes inicial >";
        while(!(cin>>lowerDay)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<endl<<"Ingresa el dia del mes inicial >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<"Ingresa la hora >";
        while(!(cin>>inputHourLower)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<endl<<"Ingresa la hora >";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<endl<<"Ingresa las primeras 3 letras del mes final >";cin>>upperM;
        upperM = monthFormater(upperM);
        cout<<"Ingresa el dia del mes final >";
        while(!(cin>>upperDay)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Ingresa el dia del mes final >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<"Ingresa la hora >";
        while(!(cin>>inputHourUpper)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Ingresa la hora >";
            cin.clear();
            cin.ignore(123,'\n');
        }

        if(months.find(lowerMonth) == months.end() && months.find(upperM) == months.end()) {
            cout<<endl<<"INVALID INPUT"<<endl<<endl; //Si no se encuenrta en el rango de lista niega query
        }
        else{
            if(months[lowerMonth]<=months[upperM]){ //si los meses son un frame direccional de menor a mayor realiza query
                if( (lowerDay >0 && lowerDay<31) || (upperDay > 0 && lowerDay<31) ){
                    continues = true;
                }
                else{
                    cout<<endl<<"INVALID INPUT, VERIFY MONTH AND DESIRED DATES"<<endl<<endl;
                }
            }
            else{
                cout<<endl<<"INVALID INPUT, VERIFY MONTH AND DESIRED DATES"<<endl<<endl;
            }            
        }
    }
    
    cout<<endl<<"Would you like to save the result on a file (yes/no) >";cin>>save;

    save = toLowerCase(save);

    cout<<endl<<"-----------=Query Result=-----------"<<endl<<endl;

    RegistryEntry lower{lowerMonth,lowerDay,inputHourLower,0,0," "," "}; //crea una entrada lower con parameters input 

    RegistryEntry upper{upperM,upperDay,inputHourUpper,0,0," "," "};//crea una entrada upper con parameters input 

    try{
        if(months[lower.month]>=months["Jun"] && months[upper.month]<=months["Dec"]){
            //verifica viabilidad de query a partir del rango
            
            fetched = search(list,upper,lower); //realiza query de entries
            
            cout<<fetched<<endl; //imprime query

            if(save == "yes"){ //si se dijo yes se guarda output en log file con fecha y hora como nombre
                ofstream out(str+".txt");
                out << fetched;
                out.close();
            }
        }
        else{
            //cout<<"QUERY COULDNT BE PERFORMED TIME FRAME NOT AVAILABLE"<<endl<<endl;
        }
    }catch(const exception& e){
        cout<<"QUERY COULDNT BE PERFORMED"<<endl<<endl;
    }
}

//Funcion para desplegar menu
void optionMenu(){
    cout<<endl;
    cout<<"1) Display full database"<<endl;
    cout<<"2) Search events by date"<<endl;
    cout<<"3) Exit"<<endl<<endl;
}

//Funcion para el menu
void menu(DoublyLinkedList list){
    cout<<endl<<endl;
    cout<<"8888      w 8          8    8               w       "<<endl;
    cout<<"8www .d88 w 8 .d88b .d88    8    .d8b. .d88 w 8d8b. "<<endl;
    cout<<"8    8  8 8 8 8.dP' 8  8    8    8' .8 8  8 8 8P Y8 "<<endl;
    cout<<"8    `Y88 8 8 `Y88P `Y88    8888 `Y8P' `Y88 8 8   8 "<<endl;
    cout<<"                                       wwdP         "<<endl;
    cout<<"888b.            w       w               "<<endl;
    cout<<"8  .8 .d88b .d88 w d88b w8ww 8d8b Yb  dP "<<endl;
    cout<<"8wwK' 8.dP' 8  8 8 `Yb.  8   8P    YbdP  "<<endl;
    cout<<"8  Yb `Y88P `Y88 8 Y88P  Y8P 8      dP   "<<endl;
    cout<<"            wwdP                   dP    "<<endl<<endl<<endl;

    line(); //estilo

    cout<<endl<<"Loading database ";
    

    cout<<endl;

    //se imprimen datos del registry
    cout<<endl<<"SUCCESS: "<<list.getSize()<<" registries have been loaded "<<endl<<endl;
   
    line();

    bool continues = true;
    int selection;
    string lowerMonth,upperMonth;
    int saveQuery;


    while(continues){
        optionMenu();
        cout<<"Selection >";
        while(!(cin>>selection)){//Evitar loop input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Selection >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<endl;
        switch (selection){//switch para la opcion 
            case 1:
                line();
                list.printList();//imprimir registry ordenado
                cout<<endl;
                line();
                break;
            case 2:
                fetchQuery(list);//realizar query
                cout<<endl;
                line();
                break;
            case 3:
                continues=false; //cerrar programa
                break;
            default:
                cout<<endl;
                line();
                cout<<endl<<"OPCION NO VALIDA"<<endl<<endl;
                line();
                break;
        }
    }
    cout<<endl;
    line();
    cout<<endl<<"FAILED LOGIN REGISTRY | TERMINATED SUCCESSFULLY"<<endl<<endl;
    line();
}


int main() {
 
  DoublyLinkedList entries;
  int option;
  int key1, k1;

  int keyCount = 0;
  
	populateMonths();//se llenan los meses
  populateMonthsReversed();

  ifstream file("./bitacora.txt"); //abre el archivo
	if(file.is_open()){
        string line;
        vector<string> words; //vector para almacenar palabras de entry
        vector<string> time;    //vector para el tiempo
        string errorString = "";    //string para el error

        int i =0;
        while(getline(file,line) /*&& i<=20*/){ //Se leen todos las entries por linea
            words = split(line," ");
            //print(words);
            RegistryEntry entry; //se crea entry y se hace split de elementos para llener el struct
            entry.month = words[0];
            entry.day = stoi(words[1]);
            time = split(words[2],":");
            entry.hour = stoi(time[0]);//
            entry.minute = stoi(time[1]);
            entry.second = stoi(time[2]);
            entry.ip = words[3];
            for (int i = 4; i < words.size(); i++){ //todos los elementos posteriores son parte del error de login
                if(i !=4 && i !=words.size()){
                    errorString= errorString+ " " + words[i];
                }
                else{
                    errorString+=words[i];
                };
            }
            
            entry.error = errorString;

            Node * n1 = new Node();
            n1 -> key = keyCount;
            n1 -> data = entry;
            entries.appendNode(n1); 

            errorString = "";
            words.clear();
            time.clear();
            keyCount++;
            i++;
        }
        file.close();
    }

  //entries.printList();
  
  //entries.clear(keyCount);

  //entries.printList();

  //sortDL(entries);
  //entries.printList();

  mergeSort(&entries.head);//Ordena la lista con merge sort
  //entries.printList();

  //
  menu(entries);

  return 0;
}