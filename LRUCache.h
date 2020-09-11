#include <iostream>
#include <unordered_map>
#include "CircularLinkedList.h"
using namespace std;

enum {
    LRU,
    FIFO
} ReplacePolicy;


class LRUCache {

    private:
    
    int ReplacePolicy;
    int current_size = 0;
    int max_size;
    CircularLinkedList<pair<char,int>> _cache;
	unordered_map<char, Node<pair<char,int>>*> positions;

    public:

    LRUCache(int max_size, int ReplacePolicy) : max_size{max_size}, ReplacePolicy{ReplacePolicy} { positions.reserve(3); }

    //Esta operacion corre en O(1), ya que no requirimos buscar nada sino solo hacemos acceso directo a lo que necesitamos
    pair <char, int> getValueFromKey(char s) {
        Node<pair<char,int>>* desired_key = positions[s];
        
        if (ReplacePolicy == LRU) {
            if (desired_key->data.first != s) {
                return make_pair('0', 0);
            }
        
            if(desired_key == _cache.Front()) {
                _cache.set_Back(_cache.Front());
			    _cache.set_Front(_cache.Front()->next);
                return _cache.Back()->data;
            }
            else {
                Node<pair<char,int>>* temp =_cache.Back()->prev;
                temp->prev->next = _cache.Back();
                _cache.Back()->prev = _cache.Front();
                _cache.Back()->next = temp;
                temp->prev = _cache.Back();
                temp->next = _cache.Front();
                _cache.set_Back(temp);
                return _cache.Back()->data;
            }
        }
        else if (ReplacePolicy == FIFO) {
            if (desired_key->data.first != s) {
                return make_pair('0', 0);
            }
            return desired_key->data;
        }
        
    }

    //Este operacion corre en O(1), ya que solo o se cambia un valor ya guardado que se consigue en tiempo constante o se agrega al final del array
    void insertKeyValuePair(char k, int v) {
        if (ReplacePolicy == LRU) {
            if (current_size != max_size) {
                _cache.Insert(make_pair(k, v));
                positions[k] = _cache.Back();
                current_size++;
            }
            else {
			    if (positions[k] != NULL) {
                    if (positions[k]->data.first == k) {
                        positions[k]->data.second = v;
                        return;
                    }
                }
            _cache.Front()->data = make_pair(k, v);
			positions[k] = _cache.Front();
            pair <char, int> temp = getValueFromKey(k);
            }
        }
        else if (ReplacePolicy == FIFO) {
            if (current_size != max_size) {
                _cache.Insert(make_pair(k, v));
                positions[k] = _cache.Back();
                current_size++;
            }
            else {
                _cache.Front()->data = make_pair(k, v);
                _cache.set_Front(_cache.Front()->next);
                _cache.set_Back(_cache.Back()->next);
			    positions[k] = _cache.Front();
                positions[_cache.Front()->data.first] = _cache.Front();
                positions[_cache.Back()->data.first] = _cache.Back();
                
            }
        }
    }

    //Esta operacion es O(1) trivialmente
    pair <char, int> getMostRecentKey() {
        return _cache.Back()->data;
    }

    void print() {
        Node<pair<char,int>>* it = _cache.Front();
        cout << it->data.first << ' '; it = it->next;
        cout << it->data.first << ' '; it = it->next;
        cout << it->data.first << ' '; it = it->next;
        cout << endl;
    }
    void print_val() {
        Node<pair<char,int>>* it = _cache.Front();
        cout << it->data.second << ' '; it = it->next;
        cout << it->data.second << ' '; it = it->next;
        cout << it->data.second << ' '; it = it->next;
        cout << endl;
    }
};