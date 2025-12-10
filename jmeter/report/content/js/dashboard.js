/*
   Licensed to the Apache Software Foundation (ASF) under one or more
   contributor license agreements.  See the NOTICE file distributed with
   this work for additional information regarding copyright ownership.
   The ASF licenses this file to You under the Apache License, Version 2.0
   (the "License"); you may not use this file except in compliance with
   the License.  You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
var showControllersOnly = false;
var seriesFilter = "";
var filtersOnlySampleSeries = true;

/*
 * Add header in statistics table to group metrics by category
 * format
 *
 */
function summaryTableHeader(header) {
    var newRow = header.insertRow(-1);
    newRow.className = "tablesorter-no-sort";
    var cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Requests";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 3;
    cell.innerHTML = "Executions";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 7;
    cell.innerHTML = "Response Times (ms)";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 1;
    cell.innerHTML = "Throughput";
    newRow.appendChild(cell);

    cell = document.createElement('th');
    cell.setAttribute("data-sorter", false);
    cell.colSpan = 2;
    cell.innerHTML = "Network (KB/sec)";
    newRow.appendChild(cell);
}

/*
 * Populates the table identified by id parameter with the specified data and
 * format
 *
 */
function createTable(table, info, formatter, defaultSorts, seriesIndex, headerCreator) {
    var tableRef = table[0];

    // Create header and populate it with data.titles array
    var header = tableRef.createTHead();

    // Call callback is available
    if(headerCreator) {
        headerCreator(header);
    }

    var newRow = header.insertRow(-1);
    for (var index = 0; index < info.titles.length; index++) {
        var cell = document.createElement('th');
        cell.innerHTML = info.titles[index];
        newRow.appendChild(cell);
    }

    var tBody;

    // Create overall body if defined
    if(info.overall){
        tBody = document.createElement('tbody');
        tBody.className = "tablesorter-no-sort";
        tableRef.appendChild(tBody);
        var newRow = tBody.insertRow(-1);
        var data = info.overall.data;
        for(var index=0;index < data.length; index++){
            var cell = newRow.insertCell(-1);
            cell.innerHTML = formatter ? formatter(index, data[index]): data[index];
        }
    }

    // Create regular body
    tBody = document.createElement('tbody');
    tableRef.appendChild(tBody);

    var regexp;
    if(seriesFilter) {
        regexp = new RegExp(seriesFilter, 'i');
    }
    // Populate body with data.items array
    for(var index=0; index < info.items.length; index++){
        var item = info.items[index];
        if((!regexp || filtersOnlySampleSeries && !info.supportsControllersDiscrimination || regexp.test(item.data[seriesIndex]))
                &&
                (!showControllersOnly || !info.supportsControllersDiscrimination || item.isController)){
            if(item.data.length > 0) {
                var newRow = tBody.insertRow(-1);
                for(var col=0; col < item.data.length; col++){
                    var cell = newRow.insertCell(-1);
                    cell.innerHTML = formatter ? formatter(col, item.data[col]) : item.data[col];
                }
            }
        }
    }

    // Add support of columns sort
    table.tablesorter({sortList : defaultSorts});
}

$(document).ready(function() {

    // Customize table sorter default options
    $.extend( $.tablesorter.defaults, {
        theme: 'blue',
        cssInfoBlock: "tablesorter-no-sort",
        widthFixed: true,
        widgets: ['zebra']
    });

    var data = {"OkPercent": 100.0, "KoPercent": 0.0};
    var dataset = [
        {
            "label" : "FAIL",
            "data" : data.KoPercent,
            "color" : "#FF6347"
        },
        {
            "label" : "PASS",
            "data" : data.OkPercent,
            "color" : "#9ACD32"
        }];
    $.plot($("#flot-requests-summary"), dataset, {
        series : {
            pie : {
                show : true,
                radius : 1,
                label : {
                    show : true,
                    radius : 3 / 4,
                    formatter : function(label, series) {
                        return '<div style="font-size:8pt;text-align:center;padding:2px;color:white;">'
                            + label
                            + '<br/>'
                            + Math.round10(series.percent, -2)
                            + '%</div>';
                    },
                    background : {
                        opacity : 0.5,
                        color : '#000'
                    }
                }
            }
        },
        legend : {
            show : true
        }
    });

    // Creates APDEX table
    createTable($("#apdexTable"), {"supportsControllersDiscrimination": true, "overall": {"data": [0.2529411764705882, 500, 1500, "Total"], "isController": false}, "titles": ["Apdex", "T (Toleration threshold)", "F (Frustration threshold)", "Label"], "items": [{"data": [0.2, 500, 1500, "https://demowebshop.tricentis.com/notebooks"], "isController": false}, {"data": [0.25, 500, 1500, "https://demowebshop.tricentis.com/cart"], "isController": false}, {"data": [0.09166666666666666, 500, 1500, "https://demowebshop.tricentis.com/logout"], "isController": false}, {"data": [0.26666666666666666, 500, 1500, "https://demowebshop.tricentis.com/login"], "isController": false}, {"data": [0.29444444444444445, 500, 1500, "https://demowebshop.tricentis.com/register"], "isController": false}, {"data": [0.18333333333333332, 500, 1500, "https://demowebshop.tricentis.com/logout-1"], "isController": false}, {"data": [0.21666666666666667, 500, 1500, "https://demowebshop.tricentis.com/logout-0"], "isController": false}, {"data": [0.0, 500, 1500, "Test"], "isController": true}, {"data": [0.8666666666666667, 500, 1500, "https://demowebshop.tricentis.com/register-1"], "isController": false}, {"data": [0.3333333333333333, 500, 1500, "https://demowebshop.tricentis.com/register-0"], "isController": false}]}, function(index, item){
        switch(index){
            case 0:
                item = item.toFixed(3);
                break;
            case 1:
            case 2:
                item = formatDuration(item);
                break;
        }
        return item;
    }, [[0, 0]], 3);

    // Create statistics table
    createTable($("#statisticsTable"), {"supportsControllersDiscrimination": true, "overall": {"data": ["Total", 480, 0, 0.0, 2808.24375, 151, 16675, 1917.5, 6267.000000000004, 8649.949999999997, 10832.41, 0.8810233085729074, 16.200221179295585, 0.9606079336148936], "isController": false}, "titles": ["Label", "#Samples", "FAIL", "Error %", "Average", "Min", "Max", "Median", "90th pct", "95th pct", "99th pct", "Transactions/s", "Received", "Sent"], "items": [{"data": ["https://demowebshop.tricentis.com/notebooks", 30, 0, 0.0, 3005.133333333333, 375, 9487, 2242.5, 5941.0, 8889.699999999999, 9487.0, 0.07295737586910474, 1.807618733569391, 0.06547639494502662], "isController": false}, {"data": ["https://demowebshop.tricentis.com/cart", 60, 0, 0.0, 2763.833333333333, 321, 11619, 1906.5, 6434.5, 7656.349999999995, 11619.0, 0.14183290665267248, 2.30395368091851, 0.1437720284233145], "isController": false}, {"data": ["https://demowebshop.tricentis.com/logout", 60, 0, 0.0, 5140.583333333333, 617, 16675, 4402.0, 10276.1, 10862.05, 16675.0, 0.12414700660875899, 4.356905250487277, 0.21871210929902463], "isController": false}, {"data": ["https://demowebshop.tricentis.com/login", 60, 0, 0.0, 2661.1833333333334, 285, 10258, 1858.5, 5923.4, 6727.649999999999, 10258.0, 0.1367278295824332, 3.058639824430073, 0.13038547420629495], "isController": false}, {"data": ["https://demowebshop.tricentis.com/register", 90, 0, 0.0, 2587.277777777778, 291, 9767, 1556.0, 5812.9000000000015, 8254.45, 9767.0, 0.19040889251841148, 3.164184232768524, 0.21966442548347992], "isController": false}, {"data": ["https://demowebshop.tricentis.com/logout-1", 60, 0, 0.0, 2864.4666666666662, 370, 9949, 2085.0, 6080.3, 7950.299999999996, 9949.0, 0.1249838562519008, 4.307304967899979, 0.11106963788010715], "isController": false}, {"data": ["https://demowebshop.tricentis.com/logout-0", 60, 0, 0.0, 2275.216666666667, 247, 6725, 2100.5, 4836.5, 5157.95, 6725.0, 0.12433918901836281, 0.07856196806140699, 0.10855394041251598], "isController": false}, {"data": ["Test", 30, 0, 0.0, 31898.166666666664, 7831, 55380, 29372.5, 53298.100000000006, 54498.9, 55380.0, 0.0695279745805725, 15.43856001191246, 0.821570793383718], "isController": true}, {"data": ["https://demowebshop.tricentis.com/register-1", 30, 0, 0.0, 384.79999999999995, 151, 1900, 300.5, 680.5000000000001, 1281.249999999999, 1900.0, 0.07182067813084292, 0.10485538457579116, 0.06677078669976802], "isController": false}, {"data": ["https://demowebshop.tricentis.com/register-0", 30, 0, 0.0, 2369.566666666667, 231, 9601, 1565.0, 5685.900000000002, 8566.449999999999, 9601.0, 0.0716751681379986, 0.03653753688284694, 0.08427431878725615], "isController": false}]}, function(index, item){
        switch(index){
            // Errors pct
            case 3:
                item = item.toFixed(2) + '%';
                break;
            // Mean
            case 4:
            // Mean
            case 7:
            // Median
            case 8:
            // Percentile 1
            case 9:
            // Percentile 2
            case 10:
            // Percentile 3
            case 11:
            // Throughput
            case 12:
            // Kbytes/s
            case 13:
            // Sent Kbytes/s
                item = item.toFixed(2);
                break;
        }
        return item;
    }, [[0, 0]], 0, summaryTableHeader);

    // Create error table
    createTable($("#errorsTable"), {"supportsControllersDiscrimination": false, "titles": ["Type of error", "Number of errors", "% in errors", "% in all samples"], "items": []}, function(index, item){
        switch(index){
            case 2:
            case 3:
                item = item.toFixed(2) + '%';
                break;
        }
        return item;
    }, [[1, 1]]);

        // Create top5 errors by sampler
    createTable($("#top5ErrorsBySamplerTable"), {"supportsControllersDiscrimination": false, "overall": {"data": ["Total", 480, 0, "", "", "", "", "", "", "", "", "", ""], "isController": false}, "titles": ["Sample", "#Samples", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors", "Error", "#Errors"], "items": [{"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}, {"data": [], "isController": false}]}, function(index, item){
        return item;
    }, [[0, 0]], 0);

});
