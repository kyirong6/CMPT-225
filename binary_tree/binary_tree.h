class binary_tree {
	private:
		class Node {
			public:
				Node(int val) {
					key = val;
				}
				int key;
				Node * left;
				Node * right;
		};
		Node *root;	
	public:
		binary_tree() {
			root = NULL;
		}
		
		bool search(Node &root, int key) {
			if (key == root->key) {
				return true;
			}
			if (key < root->key) {
				search(root->left, key);
			}
			if (key > root->key) {
				search(root->right, key);
			} else {
				return false;
			}
		}

		void insert(Node &root, int key) {
			if (key <= root->key) {
				if (root->left != NULL){
					insert(root->left, key);
				} else {
					Node node = Node(key);
					root->left=node;
				}
			}
			if (key <= root->key) {
				if (root-> != NULL) {
					insert(root->right, key);
				} else {
					Node node = Node(key);
					root->right = node;
					
				}
			}
		}		
};
