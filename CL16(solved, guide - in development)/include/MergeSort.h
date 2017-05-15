#ifndef MERGESORT_H
#define MERGESORT_H

template <typename T>
class Merger
{
    private:
        T* arr;
        int arrSize;
        void Sorting(int left, int right)
        {
            if (left < right)
            {
                int mid = left + (right - left) / 2;
                Sorting(left, mid);
                Sorting(mid + 1, right);

                T* buf = new T[right - left + 1];
                for (int k = 0; k <= right - left; k++)
                {
                    buf[k] = arr[k + left];
                }
                int first = 0;
                int second = mid - left + 1;

                for (int index = left; index <= right; index++)
                {
                    if (first + left > mid)
                    {
                        arr[index] = buf[second];
                        second++;
                    }
                    else if (second + left > right)
                    {
                        arr[index] = buf[first];
                        first++;
                    }
                    else if (buf[first] < buf[second])
                    {
                        arr[index] = buf[first];
                        first++;
                    }
                    else
                    {
                        arr[index] = buf[second];
                        second++;
                    }
                }
                delete[] buf;
            }
        }
    public:
        Merger(T* init, int _arrSize)
        {
            arrSize = _arrSize;
            arr = new T[arrSize];
            for (int i = 0; i < arrSize; i++)
            {
                arr[i] = init[i];
            }
        }

        void sortArr()
        {
            Sorting(0, arrSize - 1);
        }

        void print()
        {
            for (int i = 0; i < arrSize; i++)
            {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        ~Merger()
        {
            delete[] arr;
        }
};

#endif // MERGESORT_H
