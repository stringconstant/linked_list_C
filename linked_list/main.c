#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"



int main(int argc, const char * argv[]) {
    ll_t* l = (ll_t*) malloc(sizeof(ll_t));
    listInit(l);
    
    char* s = "William";
    char* another = "Johnny";
    char* text = "Henry";
    char* ss = "Woooooo";
    char* replacement = "Hewson";
    
    append(l, s);
    append(l, another);
    push(l, another);
    insertAtIndex(l, 2,text);
    append(l, ss);
    count(l);
    print(l);
    removeAtIndex(l, 3);
    count(l);
    print(l);
    replace(l, 4, replacement);
    count(l);
    print(l);
    search(l, "Johnny");
    search(l, "Minster");
    search(l, "William");
    getAtIndex(l, 2);
    
    
    
    printf("Done");
    return 0;
}


void listInit(ll_t * list){
	list -> head = NULL;
	list -> size = 0;
}

void print(ll_t * list){
	ll_node* temp;
	temp = list -> head;
	while(temp != NULL){
		printf("%s\n",temp -> payload);
		temp = temp->next;
	}
}

void append(ll_t * list, void*data){
	ll_node* current = list->head;
    
    if (current == NULL){
        list -> head = (ll_node*) malloc(sizeof(ll_node));
        list -> head -> payload = data;
        list -> head -> next = NULL;
    }else{
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = (ll_node*) malloc(sizeof(ll_node));
        current -> next -> payload = data;
        current -> next -> next = NULL;
    }

}

void push(ll_t * list, void*data){ // ->->-> (a thing) -> list
	ll_node* newNode;
	newNode = (ll_node*) malloc(sizeof(ll_node));
	newNode -> payload = data;
	newNode -> next = list -> head;
	list -> head = newNode;
}

void insertAtIndex(ll_t* list, int position, void* data){
    ll_node* tmp;
    tmp = (ll_node*) malloc(sizeof(ll_node));
    tmp -> payload = data;
    tmp -> next = NULL;
    ll_node* current = list -> head;
    ll_node* aftercurrent = list -> head;
    

    if (position == 1){
        tmp->next = list->head;
        list->head = tmp;
    }else{
        for (int index = 0;index < (position-1);index++){
            if (current != NULL){
                current = current -> next;
            }
        }
        aftercurrent = current -> next;
        current -> next = tmp;
        tmp -> next = aftercurrent;
    }
}

void removeAtIndex(ll_t* list, int position){
    ll_node* before = list->head;
    
    if (position == 1){
        list -> head = list->head->next;
    }else{
        for (int index =0;index<(position-2);index++){
            before = before -> next;
        }
        before -> next = before -> next -> next;
    }
    
}


void search(ll_t* list, void* data){
    ll_node* current = list -> head;
    int counter = 0;
    while (current -> next != NULL){
        if (current -> payload == data){
            counter++;
        }
        current = current -> next;
    }
    if (counter == 0){
        printf("%s is not founded in the list\n",data);
    }else{
        printf("%s is founded in the list for %d times\n",data,counter);
    }
}

void replace(ll_t* list, int position, void*data){
    ll_node* current = list -> head;
    for (int index = 0; index < position -1; index++){
        if(current -> next != NULL){
            current = current -> next;
        }
    }
    current -> payload = data;
}

void getAtIndex(ll_t* list, int position){
    ll_node* current = list -> head;
    for (int index = 0; index < position-1; index ++){
        if (current -> next != NULL){
            current = current -> next;
        }
    }
    printf("The value at index %d is %s\n",position,current->payload);
}


void count(ll_t* list){
    ll_node * current = list->head;
    int counter = 0;
    
    while (current -> next != NULL){
        current = current -> next;
        counter ++;
    }
    
    printf("There are %d items in the list\n",counter+1);
}

void destroy(ll_t* list) { // under construction
    list->head = NULL;
    list->end = NULL;
    free(list);
}


