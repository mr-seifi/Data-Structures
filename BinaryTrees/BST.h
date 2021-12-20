#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H

#include "BT.cpp"

template <typename Node, typename T>
class BST : public BT<Node, T>{
    template<typename U, typename X>
    friend std::ostream &operator<<(std::ostream&, const BST<U, X>&);
public:
    T findEQ(const T&) const;
    T find(const T&) const;
    Node *findLast(const T&);
    bool addChild(Node*, Node*);
    virtual bool add(const T&);
    bool add(Node*);
    void splice(Node*);
    void remove(Node*);
};


#endif //DATA_STRUCTURES_BST_H
