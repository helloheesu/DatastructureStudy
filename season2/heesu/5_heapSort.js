function maxHeapify (array, rootIdx) {
	if (!array || !(length in array)) return;

	var leftIdx = rootIdx * 2;
	var rightIdx = leftIdx + 1;

	var largestIdx = rootIdx;
	if (rightIdx <= array.length && array[rightIdx] > array[largestIdx]) {
		largestIdx = rightIdx;
	}
	if (leftIdx <= array.length && array[leftIdx] > array[largestIdx]) {
		largestIdx = leftIdx;
	}
	if (largestIdx != rootIdx) {
		var temp = array[largestIdx];
		array[largestIdx] = array[rootIdx];
		array[rootIdx] = temp;

		maxHeapify(array, largestIdx);
	}
}

function isMaxHeap (array, rootIdx) {
	if (!array || !(length in array)) return;

	var leftIdx = rootIdx * 2;
	var rightIdx = leftIdx + 1;
	if (leftIdx > array.length)
		return true;

	if (array[leftIdx] > array[rootIdx]) {
		return false;
	}
	if (rightIdx <= array.length && array[rightIdx] > array[rootIdx]) { // <= length 검사 안 해도 될 듯. undefined 뜰 테니까.
		return false;
	}
	return isMaxHeap(array, leftIdx) && isMaxHeap(array, rightIdx);
}
