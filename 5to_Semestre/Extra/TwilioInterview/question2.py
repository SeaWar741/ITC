

def validatePhoneNumberFormat(address):
    #check if number is E.164 format
    if len(address) == 11 or (len(address) == 12 and address[0] == '+'):
        return "SMS"
    #check if string contains wechat in the address and length is 16
    elif "wechat:" in address.lower() and len(address) == 16:
        #remove wechat from the address
        address = address.replace("wechat:", "")
        #check that the address does not contain any other special characters
        if address.isalnum():
            return "WECHAT"
    #check if string contains messenger and is followed by E.164 format
    elif "messenger" in address.lower():
        #remove messenger from address
        address = address.replace("messenger", "")
        if len(address) == 11 or (len(address) == 12 and address[0] == '+'):
            return "MESSENGER"
    else:
        return