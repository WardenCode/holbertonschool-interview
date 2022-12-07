# 0x00. Lockboxes

Solution of Lockboxes Challenge.

You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

## Tests:

```py
	boxes = [[1], [2], [3], [4], []]
	print(canUnlockAll(boxes))

	boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
	print(canUnlockAll(boxes))

	boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
	print(canUnlockAll(boxes))
```

## Expected Result

```py
	True
	True
	False
```