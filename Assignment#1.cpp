#include<iostream>

#include<cmath>

using namespace std;

class ArrayList {
  private:
    int * current;
    int * temp;
    int listSize;
  public:
    ArrayList(const int size) {
      this->listSize = size;
      this->current = new int[size];
    };
    
    void inputOfList() {
      this->temp = current;
      for (int i = 0; i < this->listSize; i++) {
          cin >> *this->temp;
          this->temp++;
      }
    }

    void displayTheList() {
      this->temp = this->current;
      cout << "The element of array are: ";
      while(this->temp != NULL) {
          cout << * this->temp << " ";
          this->temp++;
      }
      cout << endl;
    }

    int get(int index) {
      this->temp = this->current;
      int counter = 0;
      
      while(this->temp != NULL && counter < index) {
          counter++;
          this->temp++;
      }
      
      // return a valid value if index is valid
      if(counter == index) return *this->temp;
      
      // return -1 or invalid value if the index is not valid
      return -1;
    }

    void update(int value, int index) {
      this->temp = this->current;
      int counter = 0;
      
      while(this->temp != NULL && counter < index) {
          counter++;
          this->temp++;
      }
      
      // index is valid update the value
      if(counter == index) {
          *(this->temp) = value;
      }
    }

    int length() {
      int size = 0;
      this->temp = this->current;
      
      while(this->temp != NULL) {
          size++;
          this->temp++;
      }
      
      return size;
    }

    int * start() {
        return current;
    }

    int * end() {
        this->temp = this->current;
        int* last = this->temp;
        
        while(this->temp++ != NULL) {
              last = this->temp;
        }
        
        return last;
    }

    void remove(int index) {
      this->temp = this->current;
      int counter = 0;
      while(this->temp != NULL) {
          counter++;
          
          if(counter >= index) {
              *(this->temp) = *(++this->temp);
          } else {
              this->temp++;
          }
      }
    }

    void add(int value, int index) {
      this->temp = this->current;
      int counter = 0;
      int* newList = new int[this->listSize];
      int* newListCurrent = newList;
      while(this->temp != NULL && index > counter) {
          counter++;
          *(newList) = *(this->temp);
          newList++;
          this->temp++;
      }
      
      
      if(index == counter && index < this->listSize) {
          // shift the previous value one ahead
          *(newList) = value;
          newList++;
          counter++;
      }
      
      while(this->temp != NULL && counter < this->listSize) {
          *(newList) = *(this->temp);
          newList++;
          this->temp++;
      }
      
      this->current = newListCurrent;
    }
};

int main() {
    ArrayList* myList = new ArrayList(4);
    myList->inputOfList();
    myList->displayTheList();
    return 0;
}
