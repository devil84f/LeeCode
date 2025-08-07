import { Resource } from '@/types';

// 初始资源数据
export const initialResources: Resource[] = [
  {
    id: '1',
    title: '基于深度学习的调度优化算法研究',
    typeId: '1',
    content: '本文提出了一种基于深度学习的调度优化算法，通过神经网络模型预测最优调度方案...',
    author: '张明',
    createdAt: new Date('2025-03-15'),
    updatedAt: new Date('2025-03-15'),
    tags: ['深度学习', '调度优化'],
  },
  {
    id: '2',
    title: '2024年度研究进展报告',
    typeId: '2',
    content: '本报告总结了2024年度课题组在系统优化方向的主要研究进展...',
    author: '李华',
    createdAt: new Date('2025-01-20'),
    updatedAt: new Date('2025-01-20'),
    tags: ['年度报告', '研究进展'],
  },
  {
    id: '3',
    title: '分布式系统负载测试数据集',
    typeId: '3',
    content: '本数据集包含分布式系统在不同负载条件下的性能测试结果...',
    author: '王刚',
    createdAt: new Date('2025-02-10'),
    updatedAt: new Date('2025-02-10'),
    fileUrl: '#',
    tags: ['数据集', '性能测试'],
  },
  {
    id: '4',
    title: '遗传算法调度实现代码',
    typeId: '4',
    content: '这是基于遗传算法的调度问题求解代码实现，包含交叉、变异等操作...',
    author: '刘芳',
    createdAt: new Date('2025-04-05'),
    updatedAt: new Date('2025-04-05'),
    fileUrl: '#',
    tags: ['代码', '遗传算法'],
  },
];

// 获取所有资源
export const getResources = (): Resource[] => {
  const storedResources = localStorage.getItem('resources');
  return storedResources ? JSON.parse(storedResources) : initialResources;
};

 // 根据类型ID获取资源
 export const getResourcesByTypeId = (typeId: string): Resource[] => {
   const resources = getResources();
   // 确保typeId是字符串并正确匹配
   return resources.filter(resource => String(resource.typeId) === String(typeId));
 };

// 根据ID获取资源
export const getResourceById = (id: string): Resource | undefined => {
  const resources = getResources();
  return resources.find(resource => resource.id === id);
};

// 保存资源
export const saveResources = (resources: Resource[]): void => {
  localStorage.setItem('resources', JSON.stringify(resources));
};

// 添加新资源
export const addResource = (resource: Omit<Resource, 'id' | 'createdAt' | 'updatedAt'>): Resource => {
  const resources = getResources();
  const newResource: Resource = {
    ...resource,
    id: Date.now().toString(),
    createdAt: new Date(),
    updatedAt: new Date(),
  };
  resources.push(newResource);
  saveResources(resources);
  return newResource;
};

// 更新资源
export const updateResource = (id: string, updatedData: Partial<Resource>): Resource | null => {
  const resources = getResources();
  const index = resources.findIndex(resource => resource.id === id);
  
  if (index === -1) return null;
  
  resources[index] = {
    ...resources[index],
    ...updatedData,
    updatedAt: new Date(),
  };
  
  saveResources(resources);
  return resources[index];
};

// 删除资源
export const deleteResource = (id: string): void => {
  const resources = getResources();
  const updatedResources = resources.filter(resource => resource.id !== id);
  saveResources(updatedResources);
};