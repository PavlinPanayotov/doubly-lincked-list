#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <class T>
class List
{
public:
    struct Node{
    T m_data;
    Node* m_next;
    Node* m_prev;

    Node& operator=(const Node& element){
        m_data=element.m_data;
        m_next=element.m_next;
        m_prev=element.m_prev;
        return *this;
    }

    };

    class Iterator{
    private:
        Node* element;
    public:
        Iterator(Iterator* it){
            element->m_data=it->element->m_data;
            element->m_next=it->element->m_next;
            element->m_prev=it->element->m_prev;
        }

        Iterator():element(NULL){};

        Iterator(Node* element1){
            element=element1;
        }

        T operator*(){
            /*if (element==NULL){
                return 0;
            }*/
            return element->m_data;
        }

        Iterator operator++(){
            if (element==NULL){
                return *this;
            }

            element=element->m_next;
            return *this;
        }

        Iterator operator++(int){
            if (this->element==NULL){
                return *this;
            }
            Iterator* current=this;

            this->element=this->element->m_next;
            return *current;
        }

        bool operator!=(Iterator it){
            if ((element==NULL)&&(it.element==NULL)) {
                return false;
            }

            if ((element==NULL)||(it.element==NULL)){
                return true;
            }

            return (!((element->m_data==it.element->m_data)));
        }

    friend class List;
    };

    List();
    List(const List* copyList);
    ~List();
    void push_front(const T& value);
    void pop_front();
    void push_back(const T& value);
    void pop_back();
    T back();
    T front();
    int size();
    void clear();
    bool empty();
    Iterator begin();
    Iterator end();
    void erase(Iterator it);
    void insert(Iterator it, const T& value);

private:
    Node* first;
    Node* last;
    unsigned int listSize;
};

template<class T> List<T>::List(const List* copyList){
    if (copyList.size()==0){
        first=last=NULL;
        listSize=0;
    }
    else {
        listSize=copyList.size();
        first = copyList->first;
        last = copyList->last;

        for (List<T>::Iterator it = copyList.begin(); it != copyList.end(); it++)
        {
            insert(last,it.element.m_data);
        }

    }
}

template <class T> List<T>::~List(){
    clear();
}

template <class T> List<T>::List():listSize(0),first(NULL),last(NULL){

}

template<class T> void List<T>::push_front(const T& value){
    Node* randomNode= new Node;
    if (first!=NULL){
        first->m_prev=randomNode;
    }
    randomNode->m_data=value;
    randomNode->m_prev=NULL;
    randomNode->m_next=first;
    first=randomNode;
    if (listSize==0){
        last=randomNode;
    }
    listSize++;
}

template<class T> void List<T>::pop_front(){
    if (listSize==1){
        delete first;
        first=NULL;
        last=NULL;
        listSize--;
    }
    else{
        first=first->m_next;
        delete first->m_prev;
        first->m_prev=NULL;
        listSize--;
    }
}

template<class T> void List<T>::push_back(const T& value){
    Node* randomNode=new Node;
    if (last!=NULL){
        last->m_next=randomNode;
    }
    randomNode->m_data=value;
    randomNode->m_next=NULL;
    randomNode->m_prev=last;
    last=randomNode;
    if (listSize==0){
        first=randomNode;
    }
    listSize++;
}

template<class T> void List<T>::pop_back(){
    if (listSize==1){
        delete first;
        first=NULL;
        last=NULL;
        listSize--;
    }
    else{
        last=last->m_prev;
        delete last->m_next;
        last->m_next=NULL;
        listSize--;
    }
}

template<class T> T List<T>::back(){
    return last->m_data;
}

template<class T> T List<T>::front(){
    return first->m_data;
}

template<class T> int List<T>::size(){
    return listSize;
}

template<class T> void List<T>::clear(){
    Node* current;

    while(first) {
        current = first;
        first = first->m_next;
        delete current;
    }

    first=last=NULL;
    listSize=0;
}

template<class T> bool List<T>::empty(){
    return (listSize==0);
}

template<class T> typename List<T>::Iterator List<T>::begin(){
    List::Iterator it(first);
    return it;
}

template<class T> typename List<T>::Iterator List<T>::end(){
    List::Iterator it(last);
    return it;
}

template<class T> void List<T>::erase(Iterator it){
    List<T>::Iterator iter = begin();
    do{
        if (!(iter != it)){
            Node* current=iter.element;
            iter.element->m_next->m_prev=iter.element->m_prev;
            iter.element->m_prev->m_next=iter.element->m_next;
            delete current;
            return;
        }
        else{
            iter++;
        }

    }while (iter != end());
}

template<class T> void List<T>::insert(Iterator it, const T& value){
    List<T>::Iterator iter = begin();

    if (!(iter != it)){
        Node* newNode=new Node;
        newNode->m_data=value;
        newNode->m_prev=NULL;
        newNode->m_next=it.element;

        it.element->m_prev=newNode;
        first=newNode;
        listSize++;
        return;
    }
    else{
        iter++;
    }

    do{
        if (!(iter != it)){
            Node* newNode=new Node;
            newNode->m_data=value;
            newNode->m_prev=it.element->m_prev;
            newNode->m_next=it.element;

            it.element->m_prev->m_prev=newNode;
            it.element->m_prev=newNode;
            listSize++;
            return;
        }
        else{
            iter++;
        }

    }while (iter != end());
}

#endif // LIST_H_INCLUDED
