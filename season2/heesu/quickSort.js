function swap (A, a, b) {
	var temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}


function randomizedQuickSort (A, s, e) {
	debugger;
	if (s>=e) return;
	var randomIdx = Math.floor(Math.random() * (e+1-s)) + s;
	swap(A, randomIdx, e);

	var wall = partition(A, s, e);
	randomizedQuickSort(A, s, wall-1);
	randomizedQuickSort(A, wall+1, e);
}

function partition (A, s, e) {
	var wall = -1, endValue = A[e];
	for (var i = 0; i < A.length; i++) {
		if (A[i] < endValue) {
			wall++;
			swap(A, wall, i);
		}
	}
	swap(A, wall+1, e);
	return wall+1;
}

var test = [2,7,5,3,9,8,6];
randomizedQuickSort(test, 0, test.length-1);