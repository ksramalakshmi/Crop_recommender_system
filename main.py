import eel
import crop_serial

eel.init("web")
@eel.expose	

def predict():
	
    crop=crop_serial.x()
    return crop


# Start the index.html file
eel.start("index.html")
