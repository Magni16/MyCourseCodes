/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    /*----------------- Public Functions of BST -----------------*/

    BinaryTreeNode<int> *deletehelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL){
            return NULL;
        }

        if (root->data > data)
        {
            deletehelper(data, root->left);
            return root;
        }
        else if (root->data < data)
        {
            deletehelper(data, root->right);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }

            else if (root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deletehelper(rightMin, root->right);
                return root;
            }
        }
    }

    void remove(int data)
    {
        // Implement the remove() function
        this->root = deletehelper(data, this->root);
    }

    void printTree(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTree(root->left);
		printTree(root->right);
	}
    
    
    void print()
    {
        // Implement the print() function
        printTree(root);
    }

    BinaryTreeNode<int> *inserthelper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if (root->data >= data)
        {
            root->left = inserthelper(data, root->left);
        }
        else
        {
            root->right = inserthelper(data, root->right);
        }
        return root;
    }

    void insert(int data)
    {
        // Implement the insert() function
        this->root = inserthelper(data, this->root);
    }
    // helper function for search
    bool searchhelper(int data, BinaryTreeNode<int> *root)
    {

        if (root == NULL)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        else if (root->data > data)
            return searchhelper(data, root->left);

        else
            return searchhelper(data, root->right);
    }
    bool search(int data)
    {
        // Implement the search() function
        return searchhelper(data, root);
    }
};
