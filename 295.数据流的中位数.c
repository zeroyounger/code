/*
 * @lc app=leetcode.cn id=295 lang=c
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (47.50%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 43.3K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */

// @lc code=start

#define MAXSIZE 10000

typedef struct {
    int min_heap[MAXSIZE + 1];
    int max_heap[MAXSIZE + 1];
    int min_size;
    int max_size;
} MedianFinder;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 向heap中添加元素
void heapAdd(int *heap, int x, int *size) {
	if (*size > MAXSIZE) {
		return;
	}

	int child = *size;
	heap[*size] = x;
	(*size)++;

	for (int i = (child - 1) / 2; i >= 0 && child > 0; child = i, i = (i - 1) / 2) {
		if (heap[MAXSIZE] == -1) {
			if (heap[child] < heap[i]) {
				swap(&heap[child], &heap[i]);
			}
		}
		else {
			if (heap[child] > heap[i]) {
				swap(&heap[child], &heap[i]);
			}
		}
	}
}

// 在 i 开始，从上往下做heapify
void heapify(int *heap, int x, int size) {
	if (2 * x + 1 >= size) {
		return;
	}

	int child = 2 * x + 1;

	if (heap[MAXSIZE] == -1) {
		if (2 * x + 2 < size && heap[child] > heap[child + 1]) {
			child++;
		}
		if (heap[x] > heap[child]) {
			swap(&heap[x], &heap[child]);
		}
	}
	else {
		if (2 * x + 2 < size && heap[child] < heap[child + 1]) {
			child++;
		}
		if (heap[x] < heap[child]) {
			swap(&heap[x], &heap[child]);
		}
	}

	heapify(heap, child, size);
}

MedianFinder* medianFinderCreate() {
	MedianFinder* obj = (MedianFinder *)malloc(sizeof(MedianFinder));
	obj->min_size = 0;
	obj->max_size = 0;
	obj->min_heap[MAXSIZE] = -1;  // 小顶堆标志，可以采用在[0]放哨兵的方式，但是懒得修改了。
	obj->max_heap[MAXSIZE] = 1;

	return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    // 添加元素，并平衡两个堆
	if (obj->max_size <= obj->min_size) {
        if (obj->min_size > 0 && num > obj->min_heap[0]) {
            heapAdd(obj->max_heap, obj->min_heap[0], &obj->max_size);
            obj->min_heap[0] = num;
            heapify(obj->min_heap, 0, obj->min_size);
        } else {
		    heapAdd(obj->max_heap, num, &obj->max_size);
        }
	}
	else {
        if (obj->max_size > 0 && num < obj->max_heap[0]) {
            heapAdd(obj->min_heap, obj->max_heap[0], &obj->min_size);
            obj->max_heap[0] = num;
            heapify(obj->max_heap, 0, obj->max_size);
        } else {
		    heapAdd(obj->min_heap, num, &obj->min_size);
        }
	}
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->max_size == 0) {
        return 0;
    }
    if (obj->max_size > obj->min_size) {
        return obj->max_heap[0];
    } else {
        return ((double)obj->max_heap[0] + obj->min_heap[0]) / 2;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
// @lc code=end

