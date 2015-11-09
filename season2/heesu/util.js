
function isSorted (array) {
	for (var i = 0; i< array.length - 1; i++) {
		if (array[i] > array[i+1]) {
			return false;
		}
	}
	return true;
}

function getMiddleIdx (startIdx, endIdx) {
	return startIdx + ~~((endIdx-startIdx)/2);
}