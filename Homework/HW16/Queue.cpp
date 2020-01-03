//
// Created by Peter Geras on 11/2/19.
//



template<class T>
Queue<T>::Queue() {
    begin = 0;
}

template<class T>
Queue<T>::Queue(const Queue &obj) {

    begin = 0;

    for (int i = obj.begin; i < obj.vectorSize(); ++i) {

        vector<T>::push_back(obj[i]);

    }

}

template<class T>
void Queue<T>::push(int data) {
    this->push_back(data);
}

template<class T>
bool Queue<T>::pop(int &out) {

    if (begin < vector<T>::size()) {
        int temp = this->at(begin);

        begin += 1;

        out = temp;

        if (begin == vector<T>::size()) {
            begin = 0;
            this->clear();
        }
        return true;
    } else {
        return false;
    }
}

template<class T>
int Queue<T>::size() {
    return vector<T>::size() - begin;
}

template<class T>
int Queue<T>::vectorSize() const {
    return vector<T>::size();
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue &q) {

    this->clear();

    begin = 0;

    for (int i = q.begin; i < q.vectorSize(); ++i) {

        push_back(q[i]);

    }
    return *this;

}

template<class T>
Queue<T> Queue<T>::operator*(unsigned int n) {

    Queue q;

    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < this->size(); ++i) {
            q.push(this->operator[](begin + i));
        }
    }

    return q;
}





