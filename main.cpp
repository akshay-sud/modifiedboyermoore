#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Entry {
public:
    int value;
    char key;
    Entry() {
        value = 1;
        key = '0';
    };
    Entry(int data, char k) {
        value = data;
        key = k;
    }
    char returnKey() {
        return key;
    }
    int returnValue() {
        return value;
    }
};

class Entry2 {
public:
    int value;
    int key;
    Entry2() {
        value = 0;
        key = 0;
    };
    Entry2(int data, int k) {
        value = data;
        key = k;
    }
    int returnKey() {
        return key;
    }
    int returnValue() {
        return value;
    }
};

template <class T>
class Node {
public:
  T item;
  Node<T>* next;
  Node<T>* prev;
  Node();
  Node(T data) {
    item = data;
    next = nullptr;
    prev = nullptr;
  }
};

template <class T>
class List {
  Node<T>* head;
  Node<T>* tail;
  int itemCount = 0;
public:
  List() {
    head = nullptr;
    tail = nullptr;
  };
  bool isEmpty() {
    Node<T>* temp;
    temp = head;
    if (temp == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }
  bool add(T newEntry) {
// adds to end of list
    if (head == nullptr) {
      //Node<T>* a;
      //a->item = newEntry;
      Node<T>* a = new Node<T>(newEntry);
      head = a;
      tail = a;
      itemCount++;
      return true;
    }
    else {
      //Node<T>* b = new Node<T>(newEntry);
      //Node<T>* b;
      //b->item = newEntry;
      Node<T>* b = new Node<T>(newEntry);
      tail->next = b;
      b->prev = tail;
      tail = b;
      itemCount++;
      return true;
    }
  }
  bool remove(T anEntry) {
    if (head == nullptr) {
      cout << "The list is empty, cannot remove" << endl;
      return false;
    }
    else if (head->item == anEntry) {
        delete head;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
    }
    else {
      Node<T>* temp;
      temp = head;
      int counter = 0;
      while (temp->item != anEntry) {
        temp = temp->next;
        counter++;
        if (counter > itemCount) {
          cout << "The list does not contain " << anEntry << endl;
          return false;
        }
      }
      Node<T>* n;
      n = temp->prev;
      n->next = temp->next;
      if (temp->next == nullptr) {
        delete temp;
        tail = n;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
      }
      else {
        delete temp;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        temp->next->prev = n;
        return true;
      }
    }
  }
  void clear() {
    Node<T>* n;
    n = head;
    while (n) {
      cout << n->item << endl;
      if(n->prev) {
        delete n->prev;
      }
      n = n->next;
    }
    delete n;
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    cout << "The array has been successfully cleared" << endl;
  }
  int getFrequencyOf(T anEntry) {
    int counter = 0;
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            counter++;
        }
        a = a->next;
    }
    return counter;
  }
  bool contains(T anEntry) {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            return true;
        }
        a = a->next;
    }
    return false;
  }
  int returnCount() {
    return itemCount;
  }
  T returnHead() {
    return head->item;
  }
  T returnTail() {
    return tail->item;
  }

  Node<T>* getHead() {
    return head;
  }
  Node<T>* getTail() {
    return tail;
  }

  //modified
  void print() {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
      Entry2 temp = a->item;
      int data = temp.returnValue();
      int key = temp.returnKey();

      cout << "data: " << data << endl;
      cout << "key: " << key << endl;
      a = a->next;
    }
  }
  void print2() {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        Entry temp = a->item;
        int data = temp.returnValue();
        char key = temp.returnKey();

        cout << "data: " << data << endl;
        cout << "key: " << key << endl;
        a = a->next;
    }
  }
  void printReverse() {
    Node<T>* a;
    a = tail;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->prev;
    }
  }
};

template<class T>
class dynamicArray {
    T* base;
    int used;
    int size = 10;
public:
    dynamicArray();
    dynamicArray(int);
    void resize();
    void allocate(int);
    void pop();
    void push(T&);
    void set(T&, int);
    T get(int);
    T begin();
    T end();
    int length();
    int capacity();
    int getUsed();
    void setUsed(int);
    int getSize();
    void setSize(int);
};

template<class T>
dynamicArray<T>::dynamicArray(int c) {
    allocate(c);
}

template<class T>
void dynamicArray<T>::resize() {
    T* ptemp = new T [size*2];
    for (int i = 0; i < used; i++) {
        ptemp[i] = base[i];
    }
    delete [] base;
    base = ptemp;
    int x = capacity();
    x = x *2;
    setSize(x);
}

template<class T>
void dynamicArray<T>::allocate(int c) {
    setSize(c);
    base = new T [c];
}

template<class T>
void dynamicArray<T>::pop() {

    for (int i = 1; i < used; i++) {
        base[i - 1] = base[i];
        if (i == used - 2) {
            used--;
        }
        if (used == 0) {
            cout << "The value of variable 'used' is 0" << endl;
            cout << "" << endl;
        }
    }
}

template<class T>
void dynamicArray<T>::push(T& item) {
    set(item);
}

template<class T>
void dynamicArray<T>::set(T& item, int index) {
    while ((index == size) || (index > size)) {
        resize();
    }
    base[index] = item;
    used++;
}

template<class T>
T dynamicArray<T>::get(int c) {
    return base[c];
}

template<class T>
T dynamicArray<T>::begin() {
    return base[0];
}

template<class T>
T dynamicArray<T>::end() {
    return base[used - 1];
}

template<class T>
int dynamicArray<T>::length() {
    return used;
}

template<class T>
int dynamicArray<T>::capacity() {
    return size;
}

template<class T>
int dynamicArray<T>::getUsed() {
    return used;
}

template<class T>
void dynamicArray<T>::setUsed(int c) {
    used = c;
}

template<class T>
int dynamicArray<T>::getSize() {
    return size;
}

template<class T>
void dynamicArray<T>::setSize(int c) {
    size = c;
}

int hashID(dynamicArray<List<Entry>> m, char key) {
    int z = key - 97;
    if (z < -1) {
        z = 30;
        return z;
    }
    return z;
}

int hashIDgood(dynamicArray<List<Entry2>> m, int key) {
    return key;
}

Entry findBad(dynamicArray<List<Entry>> m, char key) {
    int x = hashID(m, key);
    List<Entry> y;
    y = m.get(x);
    if (y.isEmpty() == true) {
        Entry stop = Entry();
        return stop;
    }
    else {
        Entry result = y.returnHead();
        return result;
    }
}

Entry2 findGood(dynamicArray<List<Entry2>> m, int key) {
    int x = hashIDgood(m, key);
    List<Entry2> y;
    y = m.get(x);
    if (y.isEmpty() == true) {
        Entry2 end = Entry2();
        return end;
    }
    else {
        Entry2 result = y.returnHead();
        return result;
    }
}

int position(char c, string s, string t) {
    for (int o = t.length() + 1; o > 1; o--) {
        bool f = true;
        int it;
        for (int i = 0; i < s.length(); i++) {
            it = o - s.length() - 1 + i;
            if ((it >= 0) && (s[i] != t[it])) {
                f = false;
            }
        }
        it = o - s.length() - 1;
        if ((f == true) && ((it <= 0) || (t[it - 1] != c))) {
            int result;
            result = t.length() - o + 1;
            return result;
        }
    }
    return -1;
}

void BadShift(string p, dynamicArray<List<Entry>>& b) {
    for (int x = 0; x < p.length() - 1; x++) { //note to self: is it p.length or p.length -1 like in the pseudo code?
        int plength, e;
        plength = p.length();
        e = plength - x - 1;

        char key = p[x];

        //collisionCount = put(b, e, plat, collisionCount) + collisionCount;

        int z = hashID(b, key);
        List<Entry> y;
        y = b.get(z);
        if (y.isEmpty() == true) {
            Entry temp = Entry(e, key);
            bool t;
            t = y.add(temp);
            b.set(y, z);
        }
        else {
            cout << "there was a collision!" << endl;
            Entry temp = Entry(e, key);
            bool t;
            t = y.add(temp);
            b.set(y, z);
        }
    }
}

void GoodShift(string k, dynamicArray<List<Entry2>>& g) {
    string b = "";

    for (int i = 0; i < k.length(); i++) {
        int blength, pos, kindex;
        char temp;

        blength = b.length();
        kindex = k.length() - 1 - i;
        temp = k[kindex];
        pos = position(temp, b, k);

        int value = pos;
        int key = blength;

        // adding the entry to the map structure
        int z = hashIDgood(g, key);
        List<Entry2> y;
        y = g.get(z);
        if (y.isEmpty() == true) {
            Entry2* tempo = new Entry2(value, key);
            bool t;
            t = y.add(*tempo);
            g.set(y, z);
        }
        else {
            cout << "there was a collision!" << endl;
            Entry2 tempo = Entry2(value, key);
            bool t;
            t = y.add(tempo);
            g.set(y, z);
        }

        b = k[kindex] + b;
    }
}


int Search(string t, string p) {
    dynamicArray<List<Entry>> b(30);
    dynamicArray<List<Entry2>> g(10);

    // good shift start

    GoodShift(p, g);

    // good shift stop
    // bad shift start

    BadShift(p, b);

    // bad shift stop

    int i = 0;
    while (i < t.length() - p.length() + 1) {
        int j = p.length();
        while ((j > 0) && (p[j - 1] == t[i + j - 1])) {
            j -= 1;
        }
        if (j > 0) {
            char keyb = t[i + j - 1];
            int keyg = p.length() - j;
            int bs, gs;

            Entry x = findBad(b, keyb);
            bs = x.returnValue();

            Entry2 y = findGood(g, keyg);
            gs = y.returnValue();

            if (bs > gs) {
                i += bs;
            }
            else {
                i += gs;
            }
        }
        else {
            return i;
        }
    }
    return -1;
}

void Test(string t, string p) {
    string target, pattern;
    int location;

    target = t;
    pattern = p;
    location = Search(target, pattern);

    if (location != -1) {
        cout << "the location of the pattern '" << pattern << "' is at location: " << location << endl;
        cout << "in the target string: '" << target << "'" << endl;
        cout << " " << endl;
    }
    else if (location == -1) {
        cout << "the pattern was not found in the target string" << endl;
        cout << "there might be some kind of error as well, please check it yourself" << endl;
    }
    else {
        cout << "Something's really off here" << endl;
    }
}

int main() {

    Test("abcxdefg", "x");
    Test("abcxdefg", "def");
    Test("a block of text", "block");

    return 0;
}
