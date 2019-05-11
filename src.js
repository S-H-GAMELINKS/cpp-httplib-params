Vue.component('price', {
    data: function () {
        return {
            res: "" 
        }
    },
    mounted: function ()  {
        var params = new URLSearchParams();
            params.append('params', 'value1');
            params.append('param2', 'value2');
            axios.post('/post', params).then((res) => {
                console.log(res);
            }, (error) => {
                console.log(error);
            });
    },
    template: '<h1>hoge</h1>'
});