template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(nullptr) {}

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
        }
    }
};

template <typename T>
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here.
    if (!first)
        return second;
    if (!second)
        return first;
    Node<int> *mergeNode;
    if (first->data <= second->data)
    {
        mergeNode = first;
        first = first->next;
    }
    else
    {
        mergeNode = second;
        second = second->next;
    }
    Node<int> *current = mergeNode;
    while (first && second)
    {
        if (first->data <= second->data)
        {
            current->next = first;
            first = first->next;
        }
        else
        {
            current->next = second;
            second = second->next;
        }
        current = current->next;
    }
    if (first)
    {
        current->next = first;
    }
    if (second)
    {
        current->next = second;
    }
    return mergeNode;
}
