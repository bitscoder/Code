def decode(message_file):
    decoded_message = ""
    pyramid = []
    
    # Read the encoded message from the file
    with open(message_file, 'r') as file:
        for line in file:
            line = line.strip().split()
            pyramid.append(line[1])
    
    # Decode the message using the pyramid structure
    for i in range(len(pyramid)):
        decoded_message += pyramid[i] + " "
    
    return decoded_message.strip()

# Example usage
decoded_message = decode("coding_qual_input.txt")
print(decoded_message)