#ifndef LIST_H
#define LIST_H

typedef struct ll_node_ {
	void* payload;	 // pointer to anything at all
	struct ll_node_ * next;
} ll_node;

typedef struct {
	ll_node* head;
	ll_node* end;
	int size;
} ll_t;

void listInit(ll_t* list);

void print(ll_t* list);

void append(ll_t * list, void*data);

void push(ll_t* list, void* data);

void insertAtIndex(ll_t* list, int position, void* data);

void search(ll_t* list, void*data);

void replace(ll_t* list, int position, void*data);

void getAtIndex(ll_t* list, int position);

void removeAtIndex(ll_t* list, int position);

void count(ll_t* list);

void destroy(ll_t* list);





#endif 
