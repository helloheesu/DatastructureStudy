
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

function Queue () {
	this.flush();
}
Queue.prototype.isEmpty = function () {
	return this.front >= this.data.length - 1;
};
Queue.prototype.enqueue = function (value) {
	this.data.push(value);
	return this.data.length;
};
Queue.prototype.dequeue = function () {
	var data = this.data[++(this.front)];
	if (this.isEmpty()) {
		this.flush();
	}
	return data;
};
Queue.prototype.flush = function () {
	this.data = [];
	// this.rear = -1; // rear == data.length
	this.front = -1;
};