var swimInWater = function(grid) 
{
    const n = grid.length;
    const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    const minHeap = new CustomMinPriorityQueue({ priority: x => x[0] });
    const visited = new Set();
    minHeap.enqueue([grid[0][0], 0, 0]);
    visited.add(0 + ',' + 0);

    while (!minHeap.isEmpty()) 
    {
        const [time, row, col] = minHeap.dequeue().element;

        if (row === n - 1 && col === n - 1) 
        {
            return time;
        }

        for (const [dx, dy] of directions) 
        {
            const newRow = row + dx;
            const newCol = col + dy;

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited.has(newRow + ',' + newCol)) 
            {
                visited.add(newRow + ',' + newCol);
                minHeap.enqueue([Math.max(time, grid[newRow][newCol]), newRow, newCol]);
            }
        }
    }

    return 0;
};

class CustomMinPriorityQueue 
{
    constructor({ priority }) 
    {
        this.priority = priority;
        this.heap = [];
    }

    isEmpty() 
    {
        return this.heap.length === 0;
    }

    enqueue(element) 
    {
        this.heap.push(element);
        this._heapifyUp();
    }

    dequeue() 
    {
        if (this.heap.length === 1) 
        {
            return { element: this.heap.pop() };
        }

        const element = this.heap[0];
        this.heap[0] = this.heap.pop();
        this._heapifyDown();
        return { element };
    }

    _heapifyUp() {
        let index = this.heap.length - 1;
        
        while (index > 0) 
        {
            const parentIndex = Math.floor((index - 1) / 2);
        
            if (this.priority(this.heap[parentIndex]) <= this.priority(this.heap[index])) 
            {
                break;
            }
            
            [this.heap[parentIndex], this.heap[index]] = [this.heap[index], this.heap[parentIndex]];
            index = parentIndex;
        }
    }

    _heapifyDown() 
    {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[0];
    
        while (true) 
        {
            const leftChildIndex = 2 * index + 1;
            const rightChildIndex = 2 * index + 2;
            let leftChild, rightChild;
            let swap = null;

            if (leftChildIndex < length) 
            {
                leftChild = this.heap[leftChildIndex];
            
                if (this.priority(leftChild) < this.priority(element)) 
                {
                    swap = leftChildIndex;
                }
            }

            if (rightChildIndex < length) 
            {
                rightChild = this.heap[rightChildIndex];
                if (
                    (swap === null && this.priority(rightChild) < this.priority(element)) ||
                    (swap !== null && this.priority(rightChild) < this.priority(leftChild))
                ) 
                {
                    swap = rightChildIndex;
                }
            }

            if (swap === null) break;
            this.heap[index] = this.heap[swap];
            this.heap[swap] = element;
            index = swap;
        }
    }
}