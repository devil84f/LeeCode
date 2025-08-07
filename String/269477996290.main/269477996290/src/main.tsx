 import { StrictMode } from "react";
 import { createRoot } from "react-dom/client";
 import { BrowserRouter } from "react-router-dom";
 import { Toaster } from 'sonner';
 import App from "./App.tsx";
 import "./index.css";
 
 // 初始化本地存储数据（仅在首次加载时）
 if (!localStorage.getItem('resourceTypes')) {
   const initialTypes = [
     { 
       id: '1', 
       name: '学术论文', 
       description: '学术研究论文和期刊文章', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=academic%20paper%2C%20document%2C%20research%20icon&sign=359736457b2cbfcf17a3bc54b6f6befd'
     },
     { 
       id: '2', 
       name: '研究报告', 
       description: '研究项目的进展报告和总结报告', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=research%20report%2C%20analysis%2C%20summary%20icon&sign=37af65167cef70a9d085941db333a19e'
     },
     { 
       id: '3', 
       name: '实验数据', 
       description: '实验获得的原始数据和分析结果', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=experimental%20data%2C%20chart%2C%20statistics%20icon&sign=a2474a4072dca0633119a6e1aa4480fd'
     },
     { 
       id: '4', 
       name: '代码示例', 
       description: '研究中使用的代码和示例程序', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=code%20example%2C%20programming%2C%20script%20icon&sign=441c26a1372160ff842a5a491176f8e7'
     },
     { 
       id: '5', 
       name: '会议资料', 
       description: '学术会议的演示文稿和相关材料', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=meeting%20materials%2C%20presentation%2C%20conference%20icon&sign=d940565aebe947b4070821133a157c86'
     },
     { 
       id: '6', 
       name: '工具分享', 
       description: '研究中使用的工具和软件推荐', 
       createdAt: new Date('2025-01-15').toISOString(),
       iconUrl: 'https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=tools%20sharing%2C%20software%2C%20utility%20icon&sign=228efbc52263bfba11a46257b4372d95'
     },
   ];
   localStorage.setItem('resourceTypes', JSON.stringify(initialTypes));
 }
 
 if (!localStorage.getItem('resources')) {
   const initialResources = [
     {
       id: '1',
       title: '基于深度学习的调度优化算法研究',
       typeId: '1',
       content: '本文提出了一种基于深度学习的调度优化算法，通过神经网络模型预测最优调度方案。实验结果表明，该算法在多个测试数据集上均优于传统启发式算法，平均提升约15%的调度效率。',
       author: '张明',
       createdAt: new Date('2025-03-15').toISOString(),
       updatedAt: new Date('2025-03-15').toISOString(),
       tags: ['深度学习', '调度优化']
     },
     {
       id: '2',
       title: '2024年度研究进展报告',
       typeId: '2',
       content: '本报告总结了2024年度课题组在系统优化方向的主要研究进展，包括分布式系统调度算法、资源分配模型和能效优化策略三个方面的成果。报告还提出了2025年的研究计划和预期目标。',
       author: '李华',
       createdAt: new Date('2025-01-20').toISOString(),
       updatedAt: new Date('2025-01-20').toISOString(),
       tags: ['年度报告', '研究进展']
     },
     {
       id: '3',
       title: '分布式系统负载测试数据集',
       typeId: '3',
       content: '本数据集包含分布式系统在不同负载条件下的性能测试结果，包括响应时间、吞吐量、资源利用率等关键指标。数据集来源于100节点集群在不同任务调度策略下的实验记录。',
       author: '王刚',
       createdAt: new Date('2025-02-10').toISOString(),
       updatedAt: new Date('2025-02-10').toISOString(),
       fileUrl: '#',
       tags: ['数据集', '性能测试']
     },
     {
       id: '4',
       title: '遗传算法调度实现代码',
       typeId: '4',
       content: '这是基于遗传算法的调度问题求解代码实现，包含交叉、变异等操作。代码使用Python编写，包含完整的注释和示例用法。算法采用自适应交叉率和变异率，能够有效避免局部最优解。',
       author: '刘芳',
       createdAt: new Date('2025-04-05').toISOString(),
       updatedAt: new Date('2025-04-05').toISOString(),
       fileUrl: '#',
       tags: ['代码', '遗传算法']
     },
   ];
   localStorage.setItem('resources', JSON.stringify(initialResources));
 }
 
 createRoot(document.getElementById("root")!).render(
   <StrictMode>
     <BrowserRouter>
       <App />
       <Toaster position="top-right" />
     </BrowserRouter>
   </StrictMode>
 );
