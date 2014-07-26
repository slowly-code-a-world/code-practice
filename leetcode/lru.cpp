
LRU Cache
Total Accepted: 13686 Total Submissions: 101359

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

struct node {
    struct node* left;
    struct node* right;
    int key;
    int value;
};

class LRUCache{
private:
    unordered_map <int, int> map;
    struct node *head;
    int cap;
    int cnt;
public:
    LRUCache(int capacity) {
        head = NULL;
        cap = capacity;
        cnt = 0;    
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            if (head->key != key) {
                struct node* p = head->right;
                while (p != head) {
                    if (p->key == key)
                        break;
                    else p = p->right;    
                }
                p->left->right = p->right;
                p->right->left = p->left;
                p->right = head;
                p->left = head->left;
                head->left->right = p;
                head->left = p;
                head = p;
            }
            return map[key];
        } else return -1;
    }
    
    void set(int key, int value) {
        int ret = get(key);
        if (-1!=ret) {
            if (ret == value) return;
            map[key] = value;
            return;
        }
        else {
            cnt++;
            if (cnt > cap) {
                map[key] = value;
                struct node *p =(struct node*)malloc(sizeof(struct node));
                p->key = key;
                p->value = value;
                p->right = head;
                p->left = head->left;
                head->left->right = p;
                head->left = p;
                head = p;
                
                p = head->left;
                p->left->right = head;
                head->left = p->left;
                p->right = NULL;
                p->left = NULL;
                map.erase(p->key);
                free(p);
            } else {
                map[key] = value;
                struct node *p = (struct node*)malloc(sizeof(struct node));
                p->key = key;
                p->value = value;
                if (NULL == head) {
                    head = p;
                    head->left = head;
                    head->right = head;
                } else {
                    p->right = head;
                    p->left = head->left;
                    head->left->right = p;
                    head->left = p;
                    head = p;
                }
            }
        }    
        
    }
};
