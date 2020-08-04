#include "avltree.h"
#include <iostream>
#include <queue>
#include <string>

AvlTree::AvlTree()
{

}

AvlTree::~AvlTree()
{
    dealockNodes();
}

AVLNode *AvlTree::getRoot()
{
    return root;
}

void AvlTree::dealockNodes()
{
    if (root != nullptr)
    {
        root->dealockSubTree();
        delete root;
        root = nullptr;
    }
}

struct AVLNode* AvlTree::insert(int data)
{
    if (root == nullptr)
    {
        struct AVLNode* t = new AVLNode(data, nullptr);
        root = t;
        return t;
    }
    else
    {
        struct AVLNode* tmp = root;
        while(true)
        {
            if (data < tmp->data) //go to left
            {
                if (tmp->left == nullptr)
                {
                    struct AVLNode* t = new AVLNode(data, tmp);
                    tmp->left = t;
                    return t;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else if (data > tmp->data)
            {
                if (tmp->right == nullptr)
                {
                    struct AVLNode* t = new AVLNode(data, tmp);
                    tmp->right = t;
                    return t;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            else //data == tmp->data
            {
                return nullptr;
            }
        }
    }
}

RemoveReturn AvlTree::remove(int data)
{
    RemoveReturn ret;

    if (root == nullptr)
    {
        ret.toRemoveNode = nullptr;
        ret.newNodeInthePosition = nullptr;
        return ret;
    }

    if (root->data == data)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            ret.toRemoveNode = root;
            root = nullptr;
            ret.newNodeInthePosition = nullptr;
            return ret;
        }
        if (root->left == nullptr)
        {
            ret.toRemoveNode = root;

            root = root->right;
            if (root != nullptr)
                root->father = nullptr;

            ret.newNodeInthePosition = root;
            return ret;
        }
        else if (root->right == nullptr)
        {
            ret.toRemoveNode = root;

            root = root->left;
            if (root != nullptr)
                root->father = nullptr;

            ret.newNodeInthePosition = root;
            return ret;
        }
        else
        {
            struct AVLNode* backup = root;
            if (root->left->right == nullptr)
            {
                root = root->left;
                root->right = backup->right;

                ret.toRemoveNode = backup;
                ret.newNodeInthePosition = root;
                return ret;
            }
            else
            {
                AVLNode* fatherOfPred = getFatherOfPredecessor(root);
                root = fatherOfPred->right;
                fatherOfPred->right = root->left;
                root->left = backup->left;
                root->right = backup->right;

                ret.toRemoveNode = backup;
                ret.newNodeInthePosition = root;
                return ret;
            }
        }
    }
    else // o root não é o dado
    {
        struct AVLNode *tmp = root;
        while (tmp != nullptr)
        {
            if (data < tmp->data) //pesquisar no ramo esquerdo
            {
                if (tmp->left == nullptr)
                {
                    ret.toRemoveNode = nullptr;
                    ret.newNodeInthePosition = nullptr;
                    return ret;
                }
                if (tmp->left->data == data)
                {
                    struct AVLNode* father = tmp;
                    struct AVLNode* toRemove = tmp->left;
                    struct AVLNode* left = toRemove->left;
                    struct AVLNode* right = toRemove->right;

                    if (left == nullptr && right == nullptr)
                    {
                        tmp->left = nullptr;
                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = father;
                        return ret;
                    }
                    else if (left == nullptr)
                    {
                        father->left = right;
                        if (right != nullptr)
                            right->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = right;
                        return ret;
                    }
                    else if (right == nullptr)
                    {
                        father->left = left;
                        if (left != nullptr)
                            left->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = left;
                        return ret;
                    }
                    else
                    {
                        AVLNode* fatherOfPred = getFatherOfPredecessor(toRemove);
                        AVLNode* newNode = fatherOfPred->right;
                        fatherOfPred->right = newNode->left;
                        father->left = newNode;
                        newNode->left = left;
                        newNode->right = right;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = newNode;
                        return ret;
                    }
                }
                else
                    tmp = tmp->left;
            }
            else //pesquisar no ramo direito
            {
                if (tmp->right == nullptr)
                {
                    ret.toRemoveNode = nullptr;
                    ret.newNodeInthePosition = nullptr;
                    return ret;
                }
                if (tmp->right->data == data)
                {
                    struct AVLNode* father = tmp;
                    struct AVLNode* toRemove = tmp->right;
                    struct AVLNode* left = toRemove->left;
                    struct AVLNode* right = toRemove->right;

                    if (left == nullptr && right == nullptr)
                    {
                        tmp->right = nullptr;
                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = father;
                        return ret;
                    }
                    if (left == nullptr)
                    {
                        father->right = right;
                        if (right != nullptr)
                            right->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = right;
                        return ret;
                    }
                    else if (right == nullptr)
                    {
                        father->right = left;
                        if (left != nullptr)
                            left->father = father;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = left;
                        return ret;
                    }
                    else
                    {
                        AVLNode* fatherOfPred = getFatherOfPredecessor(toRemove);
                        AVLNode* newNode = fatherOfPred->right;
                        fatherOfPred->right = newNode->left;
                        father->right = newNode;
                        newNode->left = left;
                        newNode->right = right;

                        ret.toRemoveNode = toRemove;
                        ret.newNodeInthePosition = newNode;
                        return ret;
                    }
                }
                else
                    tmp = tmp->right;
            }

        }
    }

    ret.toRemoveNode = nullptr;
    ret.newNodeInthePosition = nullptr;
    return ret;
}

AVLNode* AvlTree::getFatherOfPredecessor(AVLNode * n)
{
    if (n->left->right == nullptr)
        return n;

    AVLNode * temp = n->left;

    while (temp->right->right != nullptr)
        temp = temp->right;
    return temp;
}

bool AvlTree::search(int data)
{
    struct AVLNode* tmp = root;

    while(tmp != nullptr)
    {
        if (tmp->data == data)
            return true;
        else
        {
            if (data < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
    }

    return false;
}

void AvlTree::updateHeightOfFullTree()
{
    updateHeightOfNode(root);
}

void AvlTree::updateHeightOfNode(struct AVLNode* node)
{
    int leftHeight = 0;
    if (node->left != nullptr)
    {
        updateHeightOfNode(node->left);
        leftHeight = node->left->height;
    }
    int rightHeight = 0;
    if (node->right != nullptr)
    {
        updateHeightOfNode(node->right);
        rightHeight = node->right->height;
    }
    node->height = 1 + std::max(leftHeight, rightHeight);
}

int AvlTree::getBalanceOfNode(struct AVLNode* node)
{
    int leftHeight = 0;
    if (node->left != nullptr)
    {
        leftHeight = node->left->height;
    }
    int rightHeight = 0;
    if (node->right != nullptr)
    {
        updateHeightOfNode(node->right);
        rightHeight = node->right->height;
    }
    return leftHeight - rightHeight;
}

AVLNode* AvlTree::insertInterface(int data)
{
    struct AVLNode* inserted = this->insert(data);
    if (inserted != nullptr)
    {
        this->updateHeightOfFullTree();
        this->checkTheNeedAndMakeRotation(inserted);
    }
    return inserted;
}

void AvlTree::checkTheNeedAndMakeRotation(AVLNode *initial)
{
    //Must perform the check to rotate operation
    struct AVLNode* tmp = initial;
    while (tmp != nullptr)
    {
        //do something
        //level of left:
        int ret = getBalanceOfNode(tmp);
        if (abs(ret)>=2)
        {
            //Deve fazer uma rotação aqui
            //identificar se está mais pesada para direita ou esquerda
            if (ret > 0) //está mais pesada para a esquerda
            {
                //Identificar se é rotação simples
                int rightP = 0;
                int leftP = 0;
                if (tmp->left->left != nullptr)
                    leftP = tmp->left->left->height;
                if (tmp->left->right != nullptr)
                    rightP = tmp->left->right->height;

                if (leftP > rightP) //rotação simples
                {
                    if (root == tmp)
                    {
                        AVLNode* backup = tmp->left->right;
                        AVLNode* backup2 = tmp->left;
                        tmp->left->right = tmp;
                        tmp->left = backup;
                        root = backup2;
                        root->father = nullptr;
                        root->right->father = root;
                        if (root->right->left != nullptr)
                            root->right->left->father = root->right;

                        //tmp passa a ser backup2
                        tmp = backup2;
                    }
                    else
                    {
                        AVLNode* parentBackup = tmp->father;
                        AVLNode* backup = tmp->left;
                        AVLNode* backup2 = backup->right;
                        backup->right = tmp;

                        //change
                        tmp->father = backup;

                        if (backup2 != nullptr)
                            backup2->father = tmp;
                        tmp->left = backup2;

                        //update backup father (pai de tmp)
                        if (backup != nullptr)
                            backup->father = parentBackup;

                        //atualizar filho ou esquerdo ou direito do
                        //pai de tmp
                        if (parentBackup->right == tmp)
                            parentBackup->right = backup;
                        else
                            parentBackup->left = backup;

                        //tmp passa a ser backup
                        tmp = backup;
                    }
                }
                else //rotação dupla
                {
                    if (root == tmp)
                    {
                        AVLNode* a = tmp;
                        AVLNode* b = a->left;
                        AVLNode* c = b->right;
                        AVLNode* cL = c->left;
                        AVLNode* cR = c->right;

                        root = c;
                        root->father = nullptr;
                        root->right = a;
                        a->father = root;
                        root->left = b;
                        b->father = root;
                        a->left = cR;
                        if (cR != nullptr)
                            cR->father = a;
                        b->right = cL;
                        if (cL != nullptr)
                            cL->father = b;

                        //c passa a ser o novo tmp
                        tmp = c;
                    }
                    else
                    {
                        AVLNode* aParent = tmp->father;
                        AVLNode* a = tmp;
                        AVLNode* b = a->left;
                        AVLNode* c = b->right;
                        AVLNode* cL = c->left;
                        AVLNode * cR = c->right;

                        c->left = b;
                        b->father = c;

                        c->right = a;
                        a->father = c;

                        a->left = cR;
                        if (cR != nullptr)
                            cR->father = a;

                        b->right = cL;
                        if (cL != nullptr)
                            cL->father = b;

                        c->father = aParent;

                        if (aParent->right == a)
                            aParent->right = c;
                        else
                            aParent->left = c;

                        //c passa a ser o novo tmp
                        tmp = c;
                    }
                }
            }
            else //está mais pesada para a direita
            {
                //identificar se é rotação simples
                int rightP = 0;
                if (tmp->right->right != nullptr)
                    rightP = tmp->right->right->height;
                int leftP = 0;
                if (tmp->right->left != nullptr)
                    leftP = tmp->right->left->height;
                if (rightP > leftP)
                {
                    if (root == tmp)
                    {
                        AVLNode* backup = tmp->right->left;
                        AVLNode* backup2 = tmp->right;
                        tmp->right->left = tmp;
                        tmp->right = backup;
                        root = backup2;
                        root->father = nullptr;
                        root->left->father = root;
                        if (root->left->right != nullptr)
                            root->left->right->father = root->left;

                        //tmp passa a ser backup2
                        tmp = backup2;
                    }
                    else
                    {
                        AVLNode* parentBackup = tmp->father;
                        AVLNode* backup = tmp->right;
                        AVLNode* backup2 = backup->left;
                        backup->left = tmp;

                        //change
                        tmp->father = backup;

                        if (backup2 != nullptr)
                            backup2->father = tmp;
                        tmp->right = backup2;

                        //update backup father (pai de tmp)
                        if (backup != nullptr)
                            backup->father = parentBackup;

                        //atualizar filho ou esquerdo ou direito do
                        //pai de tmp
                        if (parentBackup->right == tmp)
                            parentBackup->right = backup;
                        else
                            parentBackup->left = backup;

                        //tmp passa a ser backup
                        tmp = backup;
                    }
                }
                //ou rotação dupla
                else
                {
                    if (root == tmp)
                    {
                        AVLNode* a = tmp;
                        AVLNode* b = a->right;
                        AVLNode* c = a->right->left;
                        AVLNode* cL = c->left;
                        AVLNode * cR = c->right;

                        root = c;
                        root->father = nullptr;
                        root->left = a;
                        a->father = root;
                        root->right = b;
                        b->father = root;
                        a->right = cL;
                        if (cL != nullptr)
                            cL->father = a;
                        b->left = cR;
                        if (cR != nullptr)
                            cR->father = b;

                        //c passa a ser tmp
                        tmp = c;
                    }
                    else
                    {
                        AVLNode* aParent = tmp->father;
                        AVLNode* a = tmp;
                        AVLNode* b = a->right;
                        AVLNode* c = a->right->left;
                        AVLNode* cL = c->left;
                        AVLNode * cR = c->right;

                        c->left = a;
                        a->father = c;

                        c->right = b;
                        b->father = c;

                        a->right = cL;
                        if (cL != nullptr)
                            cL->father = a;

                        b->left = cR;
                        if (cR != nullptr)
                            cR->father = b;

                        c->father = aParent;

                        if (aParent->right == a)
                            aParent->right = c;
                        else
                            aParent->left = c;

                        //c passa a ser tmp
                        tmp = c;
                    }
                }
            }

            //atualizar alturas
            this->updateHeightOfFullTree();
        }

        tmp = tmp->father;
    }
}

AVLNode *AvlTree::removeInterface(int data)
{
    RemoveReturn removeReturn = this->remove(data);

    //Deve fazer as checagens por rotação,
    //começando em removeReturn.newNodeInthePosition
    this->checkTheNeedAndMakeRotation(removeReturn.newNodeInthePosition);

    return removeReturn.toRemoveNode;
}

const std::string AvlTree::gitDotFileMode2()
{
    std::string textToFile = "digraph g{";
    textToFile += "node [shape=record, height=0.1]";

    if (root == nullptr)
    {
        textToFile += "NULL;Root -> NULL;";
    }
    else
    {
        int count = 0;
        exibirSubArvore2(nullptr, true, root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string AvlTree::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (root == nullptr)
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        int count = 0;
        textToFile += "Root->"+std::to_string(root->data)+";";
        exibirSubArvore1(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string AvlTree::preOrder()
{
    std::string content;
    preOrder(root, content);
    return content;
}

const std::string AvlTree::inOrder()
{
    std::string content;
    inOrder(root, content);
    return content;
}

const std::string AvlTree::posOrder()
{
    std::string content;
    posOrder(root, content);
    return content;
}

const std::string AvlTree::InLevelOrder()
{
    std::string content;

    std::queue<AVLNode*> queue;

    if (root != nullptr)
        queue.push(root);

    AVLNode* node = nullptr;
    while(queue.size() > 0)
    {
        AVLNode* node = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        content += std::to_string(node->data)+" ";

        if (node->left != nullptr)
            queue.push(node->left);

        if (node->right != nullptr)
            queue.push(node->right);
    }

    return content;
}

void AvlTree::preOrder(struct AVLNode* node, std::string& content)
{
    if (node != nullptr)
    {
        content += std::to_string(node->data) + " ";
        preOrder(node->left, content);
        preOrder(node->right, content);
    }
}
void AvlTree::inOrder(struct AVLNode* node, std::string& content)
{
    if (node != nullptr)
    {
        inOrder(node->left, content);
        content += std::to_string(node->data) + " ";
        inOrder(node->right, content);
    }
}
void AvlTree::posOrder(struct AVLNode* node, std::string& content)
{
    if (node != nullptr)
    {
        posOrder(node->left, content);
        posOrder(node->right, content);
        content += std::to_string(node->data) + " ";
    }
}

void AvlTree::exibirSubArvore1
(
    struct AVLNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+";";

    if (n->left == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->left->data)+";";
        exibirSubArvore1
        (
            n->left,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->right->data)+";";
        exibirSubArvore1
        (
            n->right,
            content,
            count
        );
    }
}

void AvlTree::exibirSubArvore2
(
    struct AVLNode *father,
    bool isLeftSon,
    struct AVLNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+" [label = \"<l> | <m> "+std::to_string(n->data)+" | <r>\"];";

    //desenha a ligação entre o pai e ele
    if (father != nullptr)
    {
        if (isLeftSon)
            content += std::to_string(father->data)+":l->"+std::to_string(n->data)+";";
        else
            content += std::to_string(father->data)+":r->"+std::to_string(n->data)+";";
    }
    else
    {
        //é o root
        content += "ROOT[shape=none fontcolor=blue];";
        content += "ROOT->"+std::to_string(n->data)+";";
    }

    if (n->left != nullptr)
    {
        exibirSubArvore2
        (
            n,
            true, //is left
            n->left,
            content,
            count
        );
    }

    if (n->right != nullptr)
    {
        exibirSubArvore2
        (
            n,
            false, //is not left
            n->right,
            content,
            count
        );
    }
}
