def ashr(a, q, qn):
    combined = a + q + qn
    sign_bit = combined[0]
    shifted = sign_bit
    for i in range(len(combined) - 1):
        shifted += combined[i]
    return shifted[:len(a)], shifted[len(a):-1], shifted[-1]


def complement(bin_str):
    complement_str = ''
    for i in bin_str:
        if i == '1':
            complement_str += '0'
        else:
            complement_str += '1'
    carry = 1
    result = ''
    for i in range(len(complement_str) - 1, -1, -1):
        if complement_str[i] == '1' and carry == 1:
            result = '0' + result
        elif complement_str[i] == '0' and carry == 1:
            result = '1' + result
            carry = 0
        else:
            result = complement_str[i] + result
    return result


def one_neg(x, y):
    comp_x = bin(x)[2:]
    y = bin(y)[2:]
    x1 = '1' + complement(comp_x)
    bit_count = max(len(x1), len(y))

    m = ('0' * (bit_count - len(x1))) + x1
    q = ('0' * (bit_count - len(y))) + y
    a = '0' * bit_count
    qn = '0'

    for _ in range(bit_count):
        if q[-1] == '1' and qn == '0':
            a = binary_addition(a, comp_x)
        elif q[-1] == '0' and qn == '1':
            a = binary_addition(a, m)

        a, q, qn = ashr(a, q, qn)

    product = a + q
    return int(product, 2), product


def binary_addition(bin1, bin2):
    max_len = max(len(bin1), len(bin2))
    bin1 = ('0' * (max_len - len(bin1))) + bin1
    bin2 = ('0' * (max_len - len(bin2))) + bin2

    carry = 0
    result = ''
    for i in range(max_len - 1, -1, -1):
        total = carry
        total += 1 if bin1[i] == '1' else 0
        total += 1 if bin2[i] == '1' else 0
        result = ('1' if total % 2 == 1 else '0') + result
        carry = 1 if total > 1 else 0

    return result[-max_len:]


def boothmul(multiplicand, multiplier, bit_count):
    m = ('0' * (bit_count - len(multiplicand))) + multiplicand
    q = ('0' * (bit_count - len(multiplier))) + multiplier
    a = '0' * bit_count
    qn = '0'

    for _ in range(bit_count):
        if q[-1] == '1' and qn == '0':
            a = binary_addition(a, complement(m))
        elif q[-1] == '0' and qn == '1':
            a = binary_addition(a, m)

        a, q, qn = ashr(a, q, qn)

    product = a + q
    return int(product, 2), product


x = int(input("Enter first number: "))
y = int(input("Enter second number: "))

if (x > 0 and y > 0):
    multiplicand = bin(x)[2:]
    multiplier = bin(y)[2:]
    bit_count = max(len(multiplicand), len(multiplier)) + 1
    result, binary_result = boothmul(multiplicand, multiplier, bit_count)
    print("Product:", result, "\nBinary Number:", binary_result)
elif (x < 0 and y < 0):
    multiplicand = bin(x * -1)[2:]
    multiplier = bin(y * -1)[2:]
    bit_count = max(len(multiplicand), len(multiplier)) + 1
    result, binary_result = boothmul(multiplicand, multiplier, bit_count)
    print("Product:", x * y, "\nBinary Number:", binary_result)
elif (x < 0 and y > 0) or (x > 0 and y < 0):
    if (x > 0):
        x, y = y, x
    result, binary_result = one_neg(x * -1, y)
    print("Product:", x * y, "\nBinary Number:", binary_result)
else:
    print("Product: 0\nBinary Number: 0")
