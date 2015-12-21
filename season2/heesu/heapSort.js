var test = ['x', 1,7,3,6,5,2];
var test1 = ['x', 10,7,1,6,5,2];
var test2 = ['x', -4,7,3,-6,5,2];


function swap (A, aIdx, bIdx) {
	var temp = A[aIdx];
	A[aIdx] = A[bIdx];
	A[bIdx] = temp;
}


function maxheapify (A, i, end) {
	if (typeof end == "undefined") end = A.length-1;
	var leftIdx = i*2;
	var rightIdx = i*2 + 1;
	var mostIdx = i;
	if (leftIdx <= end && A[leftIdx] > A[mostIdx]) {
		mostIdx = leftIdx;
	}
	if (rightIdx <= end && A[rightIdx] > A[mostIdx]) {
		mostIdx = rightIdx;
	}
	if (i !== mostIdx) {
		swap(A, mostIdx, i);
		maxheapify(A, mostIdx, end);
	}
}


function buildMaxheap (A) {
	var len = A.length;
	for (var i = Math.floor((len-1)/2); i >= 1; i--) {
		maxheapify(A, i);
	}
}


function heapSort (A) {
	buildMaxheap(A);
	// debugger;
	for (var i = A.length - 1; i >= 1; i--) {
		var max = A[i];
		swap(A, i, 1);
		maxheapify(A, 1, i-1);
	}
}