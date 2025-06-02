/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) 
{
    const maxHeap = new MaxHeap((a, b) => distance(a) > distance(b));

    for (const point of points) 
    {
        if (maxHeap.size() < k) 
        {
            maxHeap.push(point);
        } 
        else if (distance(point) < distance(maxHeap.peek())) 
        {
            maxHeap.pop();
            maxHeap.push(point);
        }
    }

    return maxHeap.toArray();
};

function distance(point)
{
    return point[0] * point[0] + point[1] * point[1];
}

class MaxHeap 
{
    constructor(comparator) 
    {
        this.heap = [];
        this.comparator = comparator;
    }

    size() 
    {
        return this.heap.length;
    }

    peek() 
    {
        return this.heap[0];
    }

    push(val) 
    {
        this.heap.push(val);
        this._heapifyUp();
    }

    pop() 
    {
        if (this.size() > 1) 
        {
            this._swap(0, this.size() - 1);
        }
        
        const val = this.heap.pop();
        this._heapifyDown();
        
        return val;
    }

    toArray() 
    {
        return this.heap.slice();
    }

    _heapifyUp() 
    {
        let index = this.size() - 1;
        const element = this.heap[index];
    
        while (index > 0) 
        {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIndex];

            if (this.comparator(element, parent)) 
            {
                this._swap(index, parentIndex);
                index = parentIndex;
            } 
            else 
            {
                break;
            }
        }
    }

    _heapifyDown() 
    {
        let index = 0;
        const length = this.size();
        const element = this.heap[index];

        while (true) 
        {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let swapIndex = null;

            if (leftChildIndex < length) 
            {
                let leftChild = this.heap[leftChildIndex];
                if (this.comparator(leftChild, element)) 
                {
                    swapIndex = leftChildIndex;
                }
            }

            if (rightChildIndex < length) 
            {
                let rightChild = this.heap[rightChildIndex];
                if (
                    (swapIndex === null && this.comparator(rightChild, element)) ||
                    (swapIndex !== null && this.comparator(rightChild, this.heap[swapIndex]))
                ) 
                {
                    swapIndex = rightChildIndex;
                }
            }

            if (swapIndex === null)
            {
                break;
            }

            this._swap(index, swapIndex);
            index = swapIndex;
        }
    }

    _swap(i, j) 
    {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }
}