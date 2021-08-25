  Node* rotate(Node* head, int k)
    {
        for(int i=0;i<k;i++){
            
            Node* cur = head;
            Node* newhead = head->next;
            while(cur->next!=NULL){
                cur = cur->next;
            }
            cur->next = head;
            head->next = NULL;
            head = newhead;
        }
        
        return head;
        
        
    }