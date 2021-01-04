{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 138,
   "metadata": {},
   "outputs": [],
   "source": [
    "import itertools\n",
    "\n",
    "def isPrimeNum(n):\n",
    "    if n == 1 or n == 0:\n",
    "        return False\n",
    "    for i in range(2, n):\n",
    "        if n % i == 0:\n",
    "            return False\n",
    "    return True\n",
    "\n",
    "def solution(numbers):\n",
    "    nums = list()\n",
    "    for i in range(1, len(numbers)+1):\n",
    "        N = itertools.permutations(numbers, i)\n",
    "        nums.extend(map(lambda x: int(''.join(x)), N))\n",
    "    \n",
    "    res = 0\n",
    "    nums = set(nums)\n",
    "    print(nums)\n",
    "    for num in nums:\n",
    "        if isPrimeNum(num):\n",
    "            res += 1\n",
    "    return res"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.6.9"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
