konv = {"r":"р","t":"т","u":"у","i":"и","p":"п","s":"с","z":"з",
        "d":"д","f":"ф","g":"г","h":"х","k":"к","nj":"њ",
        "l":"л","c":"ц","v":"в","b":"б","n":"н","m":"м",
        "č":"ч","ć":"ћ","š":"ш","đ":"ђ","ž":"ж","lj":"љ", "dj":"ђ", "dž":"џ"}
krit = "lnd"
f = open("latinica.txt", "r", encoding = "utf8")
g = open("cirilica.txt", "w", encoding = "utf8")
ff = f.read()
i = 0
c = False
while i < len(ff):
    if ff[i].isupper():
        c = True
    if ff[i].lower() in konv:
        if ff[i].lower() not in krit:
            p = konv[ff[i].lower()]
        else:
            if ff[i + 1].lower() == "j":
                p = konv[ff[i].lower() + ff[i + 1].lower()]
                i += 1
            elif ff[i + 1].lower() == "ž":
                p = konv[ff[i].lower() + ff[i + 1].lower()]
                i += 1
            else:
                p = konv[ff[i].lower()]
    else:
        p = ff[i]
    if c:
         p = p.upper()
    c = False
    i += 1
    print(p, file = g, end = "")
f.close()
g.close()
    
