import os
import sys
import xlwt



def write_sheet(sheet, data):
    for i in range(len(data)):
        row = data[i]
        for j in range(len(row)):
            col = row[j]
            if not isinstance(col, str):
                col = str(col)
            # elif isinstance(col, unicode):
            #     col = col.encode("utf-8")
            sheet.write(i, j, col)

def write(filename, data):
    book = xlwt.Workbook("utf-8")
    if isinstance(data, list):
        for i in range(int(len(data) / 60000) +1):
            sheet = book.add_sheet("sheet%s" % (i + 1))
            write_sheet(sheet, data[i*60000: (i+1) * 60000])
    else:
        for sheet_name, sheet_data in data.iteritems():
            sheet = book.add_sheet(sheet_name)
            write_sheet(sheet, sheet_data)
    book.save(filename)



filename=sys.argv[1]
data=[]
file=open(filename)
for line in file:
	_=line.split(',')
	data.append(_)

end_filename=filename+".xls"
os.system('rm %s'%end_filename)    
write(end_filename, data)
