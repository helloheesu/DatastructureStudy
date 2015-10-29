function insertionSort (array) {
	if (array.length <= 1) {
		return array;
	}
	for (var i = 1; i < array.length; i++) {
		var currentElement = array[i];
		for (var prePos = i-1; prePos >= 0 && array[prePos] > currentElement; prePos--) {
			array[prePos+1] = array[prePos];
		}
		array[prePos+1] = currentElement;
	}
	return array;
}
