#include <iostream>

template <class Data>
class List {
	private:
		struct _list {
			Data value;
			struct _list *next;
			struct _list *prev;
		};
		typedef struct _list Dlist;

		size_t _size;
		Dlist *_front;
		Dlist *_back;

		void reccopy(const Dlist *ptr) {
			if(ptr) { // if(ptr != nullptr) {
				reccopy(ptr->next);
				push_front(ptr->value);
			}
		}
	public:
		List() {
			_size = 0;
			_front = nullptr;
			_back = nullptr;
		}

		List(const List &list) {
			_front=nullptr;
			_back=nullptr;
			_size=0;
			reccopy(list._front);
		}

		~List() {
			while(!empty()) {
			//while(_size > 0) {
				pop_front();
			}
		}

		Data &front() const {
			return _front->value;
		}

		Data &back() const {
			return _back->value;
		}

		size_t size() const {
			return _size;
		}

		size_t length() const {
			return _size;
		}

		void push_front(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->prev = nullptr;

			if(_front==nullptr) {
				newNode->next=nullptr;
				_back=newNode;
			}
			else {
				newNode->next=_front;
				_front->back = newNode;
			}

			_front=newNode;
			_size++;
		}

		void push_back(Data data) {
			Dlist *newNode = new Dlist;
			newNode->value = data;
			newNode->next=nullptr;

			if(_back!=nullptr) {
				_back->next=newNode;
				newNode->prev = _back;
			}

			if(_front==nullptr) {
				_front=newNode;
				newNode->prev = nullptr;
			}

			_back=newNode;
			_size+=1;
		}

		void pop_front() {
			Dlist *front_to_delete = _front;
			_front = _front->next;

			if(_front==nullptr) {
				_back = nullptr;
			}
			else {
				_front->prev = nullptr;
			}

			delete front_to_delete;
			_size -= 1;
		}

		//CONVERT THIS FUNCTION
		void pop_back() {
			

			if(_front == NULL) return;
			if(_front==_back) { 	
	
				Dlist *new_back = current;
				current=_front;
				_front = NULL;
				delete current;
				return;
			}
			else {
			

				Dlist *new_back = current;
				_back=_back->prev;
				_back->next=NULL;
				delete current;
			}
		}

		// leave this alone
		bool empty() const {
			return ((_front==nullptr) && (_back==nullptr));
		}

		//Modify this
		void print() {
			Dlist *temp;
			temp=_front;
			while(temp!=NULL) {
				std::cout<<temp->value<<" ";
				temp=temp->next;
			}
				
			std::cout<<std::endl;
		}

		void print_back(){
			Dlist *temp;
			temp=_back;
			while(temp!=nullptr){
			 std::cout<<temp->value<<" ";
			 temp=temp->prev;
			}

			std::cout<<std::endl;
			
		}



 	template<typename data> friend bool operator==(const List<data> &a, const List <data> &b)

 	template<typename data> friend bool operator!=(const List<data> &a, const List <data> &b)


		
		};
