#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

/*!
 * \brief The AVLNode struct
 */
struct AVLNode
{
    /*!
     * \brief AVLNode
     * \param data
     * \param father
     */
    AVLNode(int data, struct AVLNode* father):
        data(data), left(nullptr), right(nullptr), father(father)
    {}

    int data = 0;
    int height = 0;
    struct AVLNode* left = nullptr;
    struct AVLNode* right = nullptr;
    struct AVLNode* father = nullptr;

    /*!
     * \brief dealockSubTree
     */
    void dealockSubTree()
    {
        if (left != nullptr)
        {
            left->dealockSubTree();
            delete left;
            left = nullptr;
        }

        if (right != nullptr)
        {
            right->dealockSubTree();
            delete right;
            right = nullptr;
        }
    }
};

/*!
 * \brief The RemoveReturn struct
 */
struct RemoveReturn
{
    AVLNode* toRemoveNode = nullptr;
    AVLNode* newNodeInthePosition = nullptr;
};

/*!
 * \brief The AvlTree class
 */
class AvlTree
{
public:
    /*!
     * \brief AvlTree
     */
    AvlTree();

    ~AvlTree();

    AVLNode* getRoot();

    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    /*!
     * \brief insertInterface
     * \param data
     */
    AVLNode* insertInterface(int data);
    /*!
     * \brief removeInterface
     * \param data
     * \return
     */
    struct AVLNode* removeInterface(int data);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();
    /*!
     * \brief gitDotFileMode2
     * \return
     */
    const std::string gitDotFileMode2();

    /*!
     * \brief preOrder
     * \return
     */
    const std::string preOrder();
    /*!
     * \brief inOrder
     * \return
     */
    const std::string inOrder();
    /*!
     * \brief posOrder
     * \return
     */
    const std::string posOrder();
    /*!
     * \brief InLevelOrder
     * \return
     */
    const std::string InLevelOrder();

    /*!
     * \brief updateHeightOfFullTree
     */
    void updateHeightOfFullTree();
    /*!
     * \brief getBalanceOfNode
     * \param node
     * \return
     */
    int getBalanceOfNode(AVLNode *node);
    /*!
     * \brief getFatherOfPredecessor
     * \param n
     * \return
     */
    AVLNode *getFatherOfPredecessor(AVLNode *n);

private:
    struct AVLNode* root = nullptr;

    /*!
     * \brief exibirSubArvore1
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore1(AVLNode *n, std::string &content, int& count);
    /*!
     * \brief exibirSubArvore2
     * \param father
     * \param isLeftSon
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore2(AVLNode *father, bool isLeftSon, AVLNode *n, std::string &content, int &count);

    /*!
     * \brief preOrder
     * \param node
     * \param content
     */
    void preOrder(AVLNode *node, std::string &content);
    /*!
     * \brief inOrder
     * \param node
     * \param content
     */
    void inOrder(AVLNode *node, std::string &content);
    /*!
     * \brief posOrder
     * \param node
     * \param content
     */
    void posOrder(AVLNode *node, std::string &content);

    /*!
     * \brief insert
     * \param data
     * \return
     */
    struct AVLNode* insert(int data);

    /*!
     * \brief remove
     * \param data
     * \return
     */
    RemoveReturn remove(int data);
    /*!
     * \brief updateHeightOfNode
     * \param node
     */
    void updateHeightOfNode(AVLNode *node);
    /*!
     * \brief checkTheNeedAndMakeRotation
     * \param initial
     */
    void checkTheNeedAndMakeRotation(AVLNode *initial);
    /*!
     * \brief dealockNodes
     */
    void dealockNodes();
};

#endif // AVLTREE_H
