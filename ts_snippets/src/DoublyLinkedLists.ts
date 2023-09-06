type Node<T> = {
    value: T;
    prev?: Node<T>;
    next?: Node<T>;
}

export default class DoublyLinkedList<T> {
    public length: number;
    public head?: Node<T>;
    public tail?: Node<T>;

    constructor() {
        this.length = 0;
        this.head = undefined;
        this.tail = undefined;
    }

    prepend(item: number) {
        const node = { value:item } as Node<T>;
        
        this.length++;
        if(!this.head) {
            this.head = this.tail = node;
            return;
        }

        node.next = this.head;
        this.head.prev = node;
        this.head = node;
    }

    insertAt(item: number, idx: number): void {
        if (idx > this.length) {
            throw new Error("Index out of bounds");
        } 
        if (idx === this.length){
            this.append(item);
            return;
        } else if (idx === 0) {
            this.prepend(item);
            return;
        }
        this.length++;
        
        let curr = this.head;
        for (let i = 0; curr && i < idx; i++) {
            curr = curr.next;
        }
        curr = curr as Node<T>;

        const node = { value: item } as Node<T>;
    
        node.next = curr;
        node.prev = curr.prev;
        curr.prev = node;

        if(curr.prev) {
            curr.prev.next = node;
        }

    } 

    append(item: number) {
        this.length++;
        const node = { value: item } as Node<T>;
        
        // let curr = this.head;
        // for (let i = 0; curr && i < this.length; i++) {
        //     curr = curr.next;
        // }
        // curr = curr as Node<T>;

        // curr.next = node;
        // node.prev = curr;

        if (!this.tail) {
            this.head = this.tail = node;
            return;
        }

        node.prev = this.tail;
        this.tail.next = node;
        this.tail = node;
    }
}

// export default class DoublyLinkedList<T> {
//     public length: number;

    

//     constructor() {
//     }

//     prepend(item: T): void {

// }
//     insertAt(item: T, idx: number): void {

// }
//     append(item: T): void {

// }
//     remove(item: T): T | undefined {

// }
//     get(idx: number): T | undefined {

// }
//     removeAt(idx: number): T | undefined {

// }
// }