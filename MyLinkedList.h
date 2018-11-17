using namespace std;
template<typename T>
class MyLinkedList {
private:
	class Node {
	private:
		T data;
		Node* next;
	public:
		//Constructor
		Node(T d) {
			data = d;
			next = nullptr;
		}
		~Node() {
			delete next;
		}
		T getData() {
			return data;
		}
		void setData(T d) {
			data = d;
		}
		Node* getNext() {
			return next;
		}
		void setNext(Node* n) {
			next = n;
		}
        void print(){
           cout << data.toString(); 
        }
	};
	int count;
	Node* root;
public:
	//Default constructor
	MyLinkedList() :
		count(0), root(nullptr) {}

	//Copy Constructor
	MyLinkedList(const MyLinkedList& other) :
		count(other.count), root(other.root) {}

	//Destructor
	~MyLinkedList() {
		Node* prev = nullptr;
		Node* cur = root;
		while (cur) {
			prev = cur;
			cur = cur->next;
			delete prev;
		}
	}

	//Add an element to the list
	void add(T d) {
		Node* element = new Node(d);
		element->setNext(root);
		root = element;
		count++;
	}

	//Remove and return the data in the first element in the list
	T pop() {
		T d = nullptr;
		if (root) {
			d = root->getData();
			root = root->getNext();
			count--;
		}
		return d;
	}

	int size() const {
		return count;
	}

	bool empty() const {
		return count == 0;
	}

	void print() {
		Node* cur = root;
		while (cur) {
			cout << cur->print() << " ";
			cur = cur->getNext();
		}
	}
};